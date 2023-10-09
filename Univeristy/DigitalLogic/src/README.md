# Conway's Game of Life

### Basics
Conway's Game of Life is what we call a celular automaton, which is a regular grid, each in one of a finite number of states, in this case the two states are:
- Dead
- Alive

The grid is two dimensional, and normally infinite, but to describe the game logically, the most we need is a 3x3.
Each cell has 8 neighbours and follows a set of four rules, which are:

- 1: If a cell is Alive and has less than 2 neighbours, it dies.
- 2: If a cell is Alive and has 2 or 3 neighbours, it keeps living.
- 3: If a cell is Dead and has Exactly three neighbours, it lives.
- 4: If a cell is Alive and has more than 3 neighbours, it dies.

It is important to note that every cell process it state at the same time as every other cell in the grid.


### Where did we start?

Since now you know the basics, how did we start making this a circuit?
Well we chose to tackle how a cell interprets a rule first, which we did in a circuit we named LOD23S.

### LOD23S

![](https://github.com/MintzyG/MyMonoRepo/blob/master/Univeristy/DigitalLogic/imgs/LOD23S.png)

Here we receive as input the amount of neighbours the current cell has in binary, the circuit then processes
which rule to activate independent of cell state, it outputs 1 in channel 'E' if a rule is activated and then
outputs 1 in either channel '2' or '3' to identify which rule was activated, if no rule was actiivated we can assume
the cell died, since the two remaining rules are about the cell death. Since here we do nothing with the current cell state
this information is sent to the next circuit to process what happens to the cell, that circuit it CSRTA23S.

### CSRA23S

