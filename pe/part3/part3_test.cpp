#include "part3.h"
#include "part3.cpp"
#include <gtest/gtest.h>

using namespace std;

#include <array>
#include <vector>

// Class for tests that take 6 parameters for test cases.
// [0] is the size of the board.
// [1] is the x-coordinate of the starting position.
// [2] is the y-coordinate of the starting position.
// [3] is the x-coordinate of the destination position.
// [4] is the y-coordinate of the destination position.
// [5] is the expected output of findMinNumOfMoves.
class KnightSolverParamTest : public testing::TestWithParam<array<int, 6>> {};

// Check that test cases match expected.
TEST_P(KnightSolverParamTest, test_public_min_moves) {
  const int size = GetParam()[0];
  const int startx = GetParam()[1];
  const int starty = GetParam()[2];
  const int destx = GetParam()[3];
  const int desty = GetParam()[4];
  const int expected = GetParam()[5];
  KnightSolver ks(size);
  const int output = ks.findMinNumOfMoves(startx, starty, destx, desty);
  EXPECT_EQ(output, expected);
}

INSTANTIATE_TEST_CASE_P(PublicTestValues, KnightSolverParamTest,
                        testing::Values(array<int, 6>{1, 0, 0, 0, 0, 0},
                                        array<int, 6>{4, 0, 0, 0, 0, 0},
                                        array<int, 6>{3, 0, 0, 1, 2, 1},
                                        array<int, 6>{3, 0, 0, 2, 1, 1},
                                        array<int, 6>{3, 0, 0, 2, 0, 2},
                                        array<int, 6>{3, 0, 1, 2, 0, 1},
                                        array<int, 6>{3, 0, 1, 2, 2, 1},
                                        array<int, 6>{3, 0, 1, 0, 0, 3},
                                        array<int, 6>{8, 0, 0, 0, 4, 2},
                                        array<int, 6>{11, 0, 1, 10, 10, 7},
                                        array<int, 6>{4, 0, 0, 0, 4, -1}));

class KnightSolverTestWithBlocks
    : public testing::TestWithParam<
          pair<array<int, 6>, vector<array<int, 2>>>> {};

TEST_P(KnightSolverTestWithBlocks, test_public_min_moves_with_blocks) {
  const int size = GetParam().first[0];
  const int startx = GetParam().first[1];
  const int starty = GetParam().first[2];
  const int destx = GetParam().first[3];
  const int desty = GetParam().first[4];
  const int expected = GetParam().first[5];
  const vector<array<int, 2>> blocks = GetParam().second;
  KnightSolver ks(size);
  for (const auto& block : blocks) {
    ks.setBlocked(block[0], block[1]);
  }
  const int output = ks.findMinNumOfMoves(startx, starty, destx, desty);
  EXPECT_EQ(output, expected);
}

INSTANTIATE_TEST_CASE_P(
    PublicTestValues, KnightSolverTestWithBlocks,
    testing::Values(make_pair(array<int, 6>{3, 0, 0, 1, 2, -1},
                              vector<array<int, 2>>{array<int, 2>{1, 2}}),
                    make_pair(array<int, 6>{8, 0, 0, 0, 4, 4},
                              vector<array<int, 2>>{array<int, 2>{1, 2}}),
                    make_pair(array<int, 6>{8, 0, 0, 0, 4, -1},
                              vector<array<int, 2>>{array<int, 2>{1, 2},
                                                    array<int, 2>{2, 1}}),
                    make_pair(array<int, 6>{3, 0, 0, 2, 0, 6},
                              vector<array<int, 2>>{array<int, 2>{1, 2}})));
