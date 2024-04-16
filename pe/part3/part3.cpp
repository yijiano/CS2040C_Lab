
int KnightSolver::findMinNumOfMoves(int startx, int starty, int destx, int desty) {
  
  /*
  minimum. number of moves for knight to move around the 5x5 grid with him as centered

  |   | 1 | 2 | 1 |   |
  | 1 | 2 | 3 | 2 | 1 |
  | 1 | 3 | K | 3 | 1 |
  | 1 | 2 | 3 | 2 | 1 |
  |   | 1 | 2 | 1 |   |  
  
  with K as the knight himself and 0 moves to get to where he is at
  
  coincidentally, the amount of space he needs to move towards that direction is also captured within that 5x5 grid

  therefore it is impossible for the knight to move to the the adjacent squares if its stuck in a 3x3 grid
  */
  
  if (startx == destx && starty == desty) return 0;
  if (_size <= 3) return -1; //impossible to move around in 3x3

  
  return -1;
}
