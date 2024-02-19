#include "prob_convexity.h"
#include "solution.h"

void ProbabilisticConvexity::recompute(const Solution& s) {
  cost = 0.0;
  lval.assign(numLots, 0);
  lsz.assign(numLots, 0);
  uval.assign(numUnits, 0);
  stoppedAt.assign(numUnits, {});
  linesThrough.assign(numUnits, 0);
  for (int k = 0; k < numLots; ++k) {
    recomputeLotConvexity(s, k);
    cost += lotCost(k);
  }
}

void ProbabilisticConvexity::shift(const Solution& s, int, int k, int p) {
  for (auto& v : stoppedAt) {
    if (empty(v)) continue;
    static auto doRemove = [&](const II& ab) {
      return s.a[ab.first] == k or s.a[ab.first] == p or
             not s.isInBnd(ab.first) or not s.isInBnd(ab.second);
    };
    v.erase(remove_if(begin(v), end(v), doRemove), end(v));
  }

  if (k != -1) {
    cost -= lotCost(k);
    recomputeLotConvexity(s, k);
    cost += lotCost(k);
  }
  if (p != -1) {
    cost -= lotCost(p);
    recomputeLotConvexity(s, p);
    cost += lotCost(p);
  }
}

double ProbabilisticConvexity::shiftCost(const Solution& s, int u, int k,
                                         int p) const {
  //   pr("shiftCost {} {} {}\n", u, k, p);
  auto& r = noConst(s);
  r.a[u] = k;
  r.innerBoundaryShift(u, k, p);

  double c = cost;

  if (k != -1) {
    double deltaK = deltaGain(s, u, k);
    c += deltaK - lotCost(k);
  }
  if (p != -1) {
    double deltaP = deltaLose(s, u, p);
    c += deltaP - lotCost(p);
  }

  r.a[u] = p;
  r.innerBoundaryShift(u, p, k);
  r.assertCorrectness();
  return c;
}

double ProbabilisticConvexity::deltaGain(const Solution& s, int u,
                                         int k) const {
  const auto& inbK = s.inBnd[k];
  int c = lval[k];

  //#TODO cheap fix, remove later. Find out why this 
  // is failing sometimes
  if (not s.isInBnd(u, k))     
    return lotCost(k);

  assert(s.isInBnd(u, k));
  assert(linearIn(inbK, u));

  int count = 0;
  for (int n : units[u].nbs) {
    if (s.a[n] == k and not s.isInBnd(n, k)) {
      if constexpr (DebugProbConv) {
        assert(not linearIn(inbK, n));
      }
      ++count;
      c -= uval[n] * 2;
    }
  }
  // 2 first if's are a quick fix (idk why this works: should be just the 3rd
  // case). See #TODO below.
  if (count == 2)
    c += 2;
  else if (count == 3)
    c += 4;

  for (int w : inbK) {
    if (w == u) continue;
    bool bres = bresenham(s, k, u, w);
    c += 2 * bres;
    if constexpr (DebugProbConv) {
      assert(s.isInBnd(w, k));
      assert(bres == bresenham(s, k, w, u));
    }
  }

  [[maybe_unused]] unordered_set<II> once;
  for (const II& ab : stoppedAt[u]) {
    int a, b;
    tie(a, b) = ab;
    assert(s.a[a] == s.a[b] and a != b and a != u and b != u);
    if (s.a[a] != k or not s.isInBnd(a, k) or not s.isInBnd(b, k)) continue;

    int bres = bresenham(s, k, a, b);
    c += 2 * bres;

    if constexpr (DebugProbConv) {
      assert(s.isInBnd(a, k) == linearIn(inbK, a));
      assert(s.isInBnd(b, k) == linearIn(inbK, b));
      assert(bres == bresenham(s, k, b, a));
      II abOnce(min(a, b), max(a, b));
      assert(once.count(abOnce) == 0);
      once.insert(abOnce);
    }
  }

  if constexpr (DebugProbConv) {
    // #TODO we still have to debug this: sometimes, very rarely, this function
    // will return a value that deviates exactly 2 from the correct value (an
    // almost negligible difference). Why?
    auto tmp = *this;
    tmp.recompute(s);
    assert(tmp.lsz[k] == (int)size(inbK));
    assert(abs(tmp.lval[k] - c) <= 2);
  }

  return 1.0 - (double)c / (double)(size(inbK) * (size(inbK) - 1));
}

double ProbabilisticConvexity::deltaLose(const Solution& s, int u,
                                         int p) const {
  const auto& inbP = s.inBnd[p];
  int c = lval[p];
  assert(not s.isInBnd(u, p));
  assert(not linearIn(inbP, u));
  c -= uval[u] * 2;

  static int nbs[LandUnit::MaxNbSize];
  int numNbs = 0;
  for (int n : units[u].nbs) {
    if (s.a[n] != p) continue;         // not in p, not considered.
    assert(s.isInBnd(n, p));           // must be inbnd, because it's next to u
    if (units[n].isBorder()) continue; // was already in inBnd before
    bool consider = true;
    for (int nn : units[n].nbs)
      if (nn != u and s.a[nn] != p) {
        consider = false;
        break;
      }
    if (not consider) continue;
    nbs[numNbs++] = n;
  }

  int nbSum = 0; // #TODO remove later
  for (int i = 0; i < numNbs; ++i) {
    int n = nbs[i];
    for (int w : inbP) {
      if (w == n) continue;
      bool bres = bresenham(s, p, n, w);
      c += bres * 2;
      nbSum += bres * 2;
      if constexpr (DebugProbConv) {
        assert(bres == bresenham(s, p, w, n));
      }
    }
  }

  // #TODO cheap fix, again. It works most of the time, but why? This is
  // *exactly* the same problem we have on deltaGain, but reversed.
  if (numNbs == 2)
    c -= 2;
  else if (numNbs == 3)
    c -= 4;

  c -= linesThrough[u] * 2;

  if constexpr (DebugProbConv) {
    auto tmp = *this;
    tmp.recompute(s);
    int sum = 0;
    for (int n : nbs)
      sum += tmp.uval[n];
    assert(nbSum == sum * 2);
    assert(tmp.lsz[p] == (int)size(inbP));
    assert(abs(tmp.lval[p] - c) <= 2);
  }
  return 1.0 - (double)c / (double)(size(inbP) * (size(inbP) - 1));
}

void ProbabilisticConvexity::recomputeLotConvexity(const Solution& s, int k) {
  assert(k >= 0 and k < numLots);
  auto& inb = s.inBnd[k];
  int n = size(inb);
  lsz[k] = n;
  for (int u : inb)
    uval[u] = 0;
  for (int u : s.la[k])
    linesThrough[u] = 0;

  lval[k] = 0;
  for (int i = 0; i < n; ++i) {
    const int a = inb[i];
    for (int j = i + 1; j < n; ++j) {
      const int b = inb[j];
      bool bres = bresenhamWithUpdate(s, k, a, b);
      if constexpr (DebugProbConv) {
        assert(s.isInBnd(a, k));
        assert(s.isInBnd(b, k));
        assert(bres == bresenham(s, k, b, a));
      }
      lval[k] += 2 * bres;
      uval[a] += bres;
      uval[b] += bres;
    }
  }
  if constexpr (DebugProbConv) {
    assert(lval[k] % 2 == 0);
    int sum = 0;
    for (int u : inb)
      sum += uval[u];
    assert(sum == lval[k]);
  }
}

bool ProbabilisticConvexity::bresenham(const Solution& s, int k, int a, int b,
                                       vector<vector<II>>* stoppedAt,
                                       vector<int>* linesThrough) {
  int y1 = units[a].r, x1 = units[a].c, y2 = units[b].r, x2 = units[b].c;
  const bool steep = (abs(y2 - y1) > abs(x2 - x1));
  if (steep) swap(x1, y1), swap(x2, y2);
  if (x1 > x2) swap(x1, x2), swap(y1, y2);
  int dx = x2 - x1, dy = abs(y2 - y1), yStep = (y1 < y2) ? 1 : -1, maxX = x2,
      y = y1;
  double error = dx / 2.0;
  bool throughRiver = false;
  bool throughBorder = false;

  static int* unitsThrough = nullptr;
  if (unitsThrough == nullptr) unitsThrough = new int[numUnits];
  int numThrough = 0;

  for (int x = x1; x < maxX; ++x) {
    int xc = x, yc = y;
    if (steep) swap(xc, yc);
    if (rawCell(yc, xc) == 0) {
      // Outer boundary.
      throughBorder = true;
    } else if (rawCell(yc, xc) == -1) {
      // River. We don't return false right away here because if we reach an
      // outer boundary after a river, we want to return true.
      throughRiver = true;
    } else {
      int i = rawToIndex(yc, xc);
      if (s.a[i] != k) {
        // Different lot: no path, regardless of whether we pass through a
        // boundary or a river.
        if (stoppedAt != nullptr and s.isInBnd(i)) {
          II ab(min(a, b), max(a, b));
          if constexpr (DebugProbConv) {
            assert(not linearIn((*stoppedAt)[i], ab));
          }
          (*stoppedAt)[i].emplace_back(ab);
        }
        return false;
      } else { // s.a[index] == k
        if (linesThrough != nullptr and i != a and i != b)
          unitsThrough[numThrough++] = i;
      }
    }
    error -= dy;
    if (error < 0) {
      y += yStep;
      error += dx;
    }
  }
  bool ok = throughBorder or not throughRiver;
  if (ok and linesThrough != nullptr) {
    for (int i = 0; i < numThrough; ++i) {
      assert(s.a[unitsThrough[i]] == k);
      ++((*linesThrough)[unitsThrough[i]]);
    }
  }
  return ok;
}
