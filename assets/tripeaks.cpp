#include <assert.h>
#include <set>
#include <stdio.h>
#include <string.h>
#include <tuple>
#define BOARDSIZE 28
#define PILESIZE 24
#define BOARD1STROW 18

int pile[PILESIZE + 1] = {7,4,1,8,6,8,7,5,10,9,9,11,4,3,12,5,9,3,12,4,10,4,8,2};
int board[BOARDSIZE] = {13,11,6,13,11,2,11,10,6,2,6,5,1,2,5,3,7,3,12,13,1,9,7,13,12,8,1,10};

int tree[BOARDSIZE][2] = {{3, 4},   {5, 6},   {7, 8},   {9, 10},  {10, 11}, {12, 13},
                          {13, 14}, {15, 16}, {16, 17}, {18, 19}, {19, 20}, {20, 21},
                          {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {26, 27},
                          {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
                          {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
int parent[BOARDSIZE][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {0, -1},  {0, -1},  {1, -1},
                            {1, -1},  {2, -1},  {2, -1},  {3, -1},  {3, 4},   {4, -1},
                            {5, -1},  {5, 6},   {6, -1},  {7, -1},  {7, 8},   {8, -1},
                            {9, -1},  {9, 10},  {10, 11}, {11, 12}, {12, 13}, {13, 14},
                            {14, 15}, {15, 16}, {16, 17}, {17, -1}};
int found_sol = false;
std::set<std::tuple<int, int, int, int>> dp;

void branch(int pile_id, int pile_top, int active, int closed) {
  if (active == 0) {
    found_sol = true;
    return;
  }
  if (pile_id >= PILESIZE && active != 0) {
    return;
  }

  if (dp.count(std::make_tuple(pile_id, pile_top, active, closed))) return;
  dp.insert(std::make_tuple(pile_id, pile_top, active, closed));

  // option 1: test current pile on all open pos
  for (int i = 0; i < BOARDSIZE; ++i)
    if (active & (1 << i)) {
      if ((pile_top + 11) % 13 + 1 == board[i] || pile_top % 13 + 1 == board[i]) {
        int new_act = active, new_clos = closed;
        new_act ^= (1 << i); // deactivate position i
        new_clos ^= (1 << i); // close position i
        for (int j = 0; j < 2; ++j) // check parents of position
          if (parent[i][j] != -1)
            // if parent has both children already closed, then open the parent
            if ((new_clos & (1 << tree[parent[i][j]][0])) &&
                (new_clos & (1 << tree[parent[i][j]][1]))) {
              assert(!(new_act & (1 << parent[i][j])));
              new_act ^= (1 << parent[i][j]);
            }
        branch(pile_id, board[i], new_act, new_clos);
        if (found_sol) {
          printf("match pile %d to board %d (pos %d)\n", pile_top, board[i], i);
          return;
        }
      }
    }

  // option 2: pass pile to next
  branch(pile_id + 1, pile[pile_id + 1], active, closed);
  if (found_sol) {
    printf("pass pile %d -> %d\n", pile_top, pile[pile_id + 1]);
    return;
  }
}

int main() {
  int count[14];
  memset(count, 0, sizeof(count));
  for (int i = 0; i < BOARDSIZE; ++i)
    count[board[i]]++;
  for (int i = 0; i < PILESIZE; ++i)
    count[pile[i]]++;
  for (int i = 1; i <= 13; ++i) {
    if (count[i] != 4) {
      printf("count[%d] = %d.\n", i, count[i]);
      return -1;
    }
  }

  int active = 0, closed = 0;
  for (int i = BOARD1STROW; i < BOARDSIZE; ++i)
    active ^= (1 << i);
  branch(0, pile[0], active, closed);

  if (!found_sol) {
    printf("no solution exists.\n");
  }
}
