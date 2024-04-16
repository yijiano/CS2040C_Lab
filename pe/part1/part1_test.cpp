#include "part1.h"
#include "part1.cpp"
#include <gtest/gtest.h>


#include <vector>

using namespace std;

// Simple test case for output on empty tree.
TEST(Tree, test_public_empty) {
  RecordProperty("expression", "Check that empty tree outputs nothing.");
  BinarySearchTree<int> bst;
  const vector<int> expected = {-1};
  vector<int> output(expected.size(), -1);
  bst.levelOrderTraversal(output.data());
  EXPECT_EQ(output, expected);
};

// Class for tests that take pairs of vectors:
// first is the input to insert into the BST,
// second is the expected output of levelOrderTraversal.
class TreeTest : public testing::TestWithParam<pair<vector<int>, vector<int>>> {
};

template <typename T>
void check_level_order_traversal(const vector<T>& input,
                                 const vector<T>& expected) {
  BinarySearchTree<T> bst;
  for (const auto& value : input) {
    bst.insert(value);
  }

  vector<T> output(expected.size());
  bst.levelOrderTraversal(output.data());
  EXPECT_EQ(output, expected);
}

// Check that test cases match expected.
TEST_P(TreeTest, test_public_level_order_traversal) {
  check_level_order_traversal(GetParam().first, GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
    PublicTestValues, TreeTest,
    testing::Values(
        make_pair(vector<int>{1}, vector<int>{1}),
        make_pair(vector<int>{2, 1, 3}, vector<int>{2, 1, 3}),
        make_pair(vector<int>{2, 3, 1}, vector<int>{2, 1, 3}),
        make_pair(vector<int>{11, 9, 8, 10, 13, 12, 14, 7, 3, 1, 0, 2, 5, 4, 6},
                  vector<int>{11, 9, 13, 8, 10, 12, 14, 7, 3, 1, 5, 0, 2, 4,
                              6}),
        make_pair(vector<int>{7, 3, 1, 0, 2, 5, 4, 6, 11, 9, 8, 10, 13, 12, 14},
                  vector<int>{7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12,
                              14})));
