---
layout: page
permalink: /projects/
title: projects
nav: true
# nav_order: 4
description:
---

A list of projects I've worked on, or ideas. 

See also:

- [Papers](/publications/) from my Master's and PhD.
- [Course projects](/course-projects/) from when I was a student at UFRGS (2011-2023 for my Bachelor's, Master's and PhD).

***

### Projects

- (ca. 2021) [A branch-and-bound algorithm to optimally solve the game Tripeaks Solitaire](/assets/tripeaks.cpp). My wife used to play this game and once came across an instance that she couldn't solve. I decided to write a program for it and proved that the instance was actually infeasible. The game developer never responded to our e-mail, so the instance is possibly still out there frustrating unknowing players.

- (2013-current) - [Solutions to competitive programming challenges](https://github.com/AlexGliesch/competitive-programming).

- (2022) [A VLNS heuristic for the Max-Mean Dispersion Problem](https://github.com/AlexGliesch/maxmeandp). This heuristic was almost competitive, but not good enough to be published. I believe it's currently the second-best in the literature. Still, it was an interesting project, and a good excuse to learn Rust at the time.

- (2023, Incomplete) [Finding matrix multiplication algorithms using heuristic search](https://github.com/AlexGliesch/mm). This project was interesting, and I may restart it in the future. It was inspired by [this ICAPS paper](https://doi.org/10.1609/icaps.v33i1.27220). I got relatively far with it and even produced better results than the original paper using PDBs. After some time I realized my heuristic was inadmissible. Still, even with an inadmissible heuristic we might be able to search for suboptimal solutions. Unfortunately my notes are difficult to parse and it will not be easy to pick it back up.

- (2022-2023, Failed) A branch-and-price algorithm for optimal districting ([chapter](TODO) and [code](TODO)). This was supposed to be the final paper (and thesis chapter) of my PhD. After spending over a year on it, the research led nowhere. The pricing problem was difficult to solve, and column generation had severe instability issues, despite our attempts to mitigate this. It's little likely that this project is salvageable.

- (ca. 2021, Failed) An ejection chain algorithm for graph coloring. The idea was to adapt my ejection chain heuristic from [this paper](https://github.com/AlexGliesch/maxdp) to graph coloring. My first implementation was not competitive  and I ended up not moving forward with it. As a positive note, I implemented a number of heuristics for graph coloring.

- (ca. 2018) [Tested a few dispersion/convexity measures for drawing regions on a grid](/assets/convexity.pdf). This never got published, nor mentioned in my thesis. In the pdf, "Convexity (per.)" is the probabilistic measure of [Zunic and Rosin](https://doi.org/10.1109/tpami.2004.19), which works great. I also implemented a [dynamic update algorithm](/assets/prob_convexity.cpp) for it.

- (ca. 2020, Failed) Using districting algorithms for parliament seating.

- (2021, Failed) Reinforcement learning-based solutions to Atomix (Monte Carlo Tree Search).

### Project ideas

- (2024, ongoing) A heuristic search algorithm to find an optimal (or good enough) progress path for the game Satisfactory.

- (ca. 2020) An improved heuristic for Atomix. This idea is well fleshed out and I am sure it works. Please feel free to ask me for details if you'd like to pursue it.

- (ca. 2022) Develop an algorithm for maximizing the number of accessible machines/casks/kegs in a given area in the game Stardew Valley. For example, the currently best solution for casks in a cellar is [125](https://stardewcommunitywiki.com/File:Optimal_cellar_layout.png), but can we do better? Or, what is the maximum number of kegs we can place in the bus stop without intersecting with an NPC path? I have a lengthy description of the problem and possible algorithms for it. 
  - this project was possibly continued by [gmlangeloh](https://github.com/gmlangeloh) and [mrpritt](https://github.com/mrpritt). They were able to frame this as a known optimization problem.

- (ca. 2022) Similar to the above, develop an algorithm for maximizing a [flower/bee house layout](https://www.reddit.com/r/StardewValley/comments/c39f09/i_made_a_guide_for_an_optimal_bee_house_hive/) in Stardew Valley, given an input area. I haven't written anything about this or thought much about the algorithm, but I am quite sure this is NP-hard.