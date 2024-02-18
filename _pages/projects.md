---
layout: page
permalink: /projects/
title: projects
nav: true
# nav_order: 4
description:
---

A list of projects I've worked on, or ideas. If you're interested in collaborating, let me know.

***

### Completed projects

- [Papers](/publications/) from my Master's and PhD.

- [Course projects](/course-projects/) from when I was a student at UFRGS (ca. 2011-2023; Bachelor's, Master's and PhD).

- (ca. 2021) A branch-and-bound algorithm to optimally solve the game "Tripeaks Solitaire". My wife used to play this game and once came across an instance that she couldn't solve. I decided to write a program for it and proved that the instance was actually infeasible. The game developer never responded to our e-mail, so the instance is possibly still out there frustrating unknowing players.

- (2013-current) - [Solutions to competitive programming challenges](https://github.com/AlexGliesch/competitive-programming).

### Project ideas

- (2024) A heuristic search algorithm to find an optimal (or good enough) progress path for the game Satisfactory.

- (ca. 2020) An improved heuristic for Atomix. 

- (ca. 2022) Develop an algorithm for maximizing the number of accessible machines/casks/kegs in a given area in the game Stardew Valley. For example, the currently best solution for casks in a cellar is [125](https://stardewcommunitywiki.com/File:Optimal_cellar_layout.png), but can we do better? Or, what is the maximum number of kegs we can place in the bus stop without intersecting with an NPC path? I have a lengthy description of the problem and possible algorithms for it. 
  - this project was possibly continued by [gmlangeloh](https://github.com/gmlangeloh) and [mrpritt](https://github.com/mrpritt). They were able to frame this as a known optimization problem. Contact them for details.

- (ca. 2022) Similar to the above, develop an algorithm for maximizing a [flower/bee house layout](https://www.reddit.com/r/StardewValley/comments/c39f09/i_made_a_guide_for_an_optimal_bee_house_hive/) in Stardew Valley, given an input area. I haven't written anything about this or thought much about the algorithm, but I am quite sure this is NP-hard.

### Failed or not completed

- (2022) [A VLNS heuristic for the Max-Mean Dispersion Problem](https://github.com/AlexGliesch/maxmeandp). This heuristic was almost competitive, but not good enough to be published. I believe it's currently the second-best in the literature. Still, it was a fun project to work on and I managed to learn Rust in the process.

- (2023) [Finding matrix multiplication algorithms using heuristic search](https://github.com/AlexGliesch/mm). This project has been fun to work on, and I may restart it in the future. It was inspired on [this ICAPS paper](https://doi.org/10.1609/icaps.v33i1.27220). I managed to get quite far with it and even produced better results than the original paper using static PDBs. After some time I realized my heuristic was inadmissible. Still, even with an inadmissible heuristic we might be able to search for suboptimal solutions. Unfortunately my notes are difficult to parse and it will not be easy to pick it back up.

- (2022,2023) A column generation heuristic for optimal districting (with the p-median objective). This was supposed to be the final paper (and thesis chapter) of my PhD. Unfortunately, after spending over a year on it, the research led nowhere. Still, I would like to divulge the [chapter](TODO) and [code](TODO). It turned out the pricing problem was too difficult to solve, and column generation required many iterations and had severe instability issues, despite our many attempts at sophisticated techniques to mitigate this. There are a few open threads left to pursue but it's little likely I am able to salvage this project.

- (ca. 2021) An ejection chain algorithm for graph coloring. The idea was to adapt my ejection chain heuristic from [this paper](https://github.com/AlexGliesch/maxdp) to graph coloring. Unfortunately, my first implementation of the algorithm was not competitive at all and I ended up not moving forward with it. On the bright side, I implemented a number of heuristics for graph coloring.

- (ca. 2018) Tested some compactness measures for fair land allocation, as well as a local search heuristic. This never got published, nor cited in my thesis. I recall implementing a sophisticated dynamic update algorithm for the measure of [Zunic and Rosin](https://doi.org/10.1109/tpami.2004.19).

- (ca. 2020) Using districting algorithms for parliament seating.

- (2021) Reinforcement learning-based solutions to Atomix. Monte-Carlo Tree Search. 