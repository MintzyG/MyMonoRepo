# Conway's Game of Life

### Basics
Conway's Game of Life is what we call a celular automaton, which is a regular grid, each in one of a finite number of states, in this case the two states are:
- Dead
- Alive

The grid is two dimensional, and normally infinite, but to describe the game logically, the most we need is a 3x3.
Each cell has 8 neighbours and follows a set of four rules, which are:

- If a cell is Alive and has less than 2 neighbours, it dies.
- If a cell is Alive and has 2 or 3 neighbours, it keeps living.
- If a cell is Alive and has more than 3 neighbours, it dies.
- If a cell is Dead and has Exactly three neighbours, it lives.

It is important to note that every cell process it state at the same time as every other cell in the grid.


### Where did we start?

Since now you know the basics, how did we start making this a circuit?
Well we chose to tackle how a cell interprets a rule first, so ...
