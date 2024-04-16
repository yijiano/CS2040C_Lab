
#ifndef part3_header
#define part3_header

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Class for solving knight movement in Chess.
 * Board may be of arbitrary (square) size, given in the constructor.
 * Board locations are given as (x,y) pairs where 0 <= x,y < _size.
 * Knights move in an L-shape: 2 squares in one direction, then 1 square in a
 * perpendicular direction. For example: from (2, 2) the knight can move to
 * eight possible squares (assuming the board is at least 5x5): (0, 1), (0, 3),
 * (1, 0), (1, 4), (3, 0), (3, 4), (4, 1), (4, 3). Optionally, some squares may
 * be blocked by calling setBlock. The knight cannot move to a blocked square.
 */
class KnightSolver {
 private:
  // The board is _size x _size.
  int _size;

  // The board represented as a 2D array of characters.
  // You probably don't want to access this directly.
  // Stored in row-major order.
  char *_board;

  void _check_bounds(int x, int y) {
    if (x < 0 || x >= _size || y < 0 || y >= _size) {
      throw std::out_of_range("Out of bounds: " + std::to_string(x) + ", " +
                              std::to_string(y));
    }
  };

  // Helper to get the value at a board location.
  char getLocation(int x, int y) {
    _check_bounds(x, y);
    return _board[x * _size + y];
  };

  // Helper to set the value at a board location.
  void setLocation(int x, int y, char c) {
    _check_bounds(x, y);
    _board[x * _size + y] = c;
  };

 public:
  // Construct a board of dimensions size x size.
  KnightSolver(int size);

  // Helper to print out the board.
  void printBoard();

  // Helper to check if a location is blocked.
  bool isBlocked(int x, int y) {
    _check_bounds(x, y);
    return getLocation(x, y) == 'B';
  };

  // Mark a square as blocked.
  void setBlocked(int x, int y) {
    _check_bounds(x, y);
    setLocation(x, y, 'B');
  };

  int findMinNumOfMoves(int startx, int starty, int destx, int desty);
};

KnightSolver::KnightSolver(int size) {
  _size = size;
  _board = new char[_size * _size];
  for (int i = 0; i < _size * _size; ++i) {
    _board[i] = '.';
  }
}

void KnightSolver::printBoard() {
  for (int x = 0; x < _size; x++) {
    for (int y = 0; y < _size; y++) {
      cout << getLocation(x, y);
    }
    cout << endl;
  }
};

#endif /* part3_header */
