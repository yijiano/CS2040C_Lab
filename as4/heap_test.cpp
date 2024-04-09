#include "heap.hpp"
#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

TEST(Heap, test_public_constructor) {
  RecordProperty("expression",
                 "Check that default construct builds sane heap.");
  Heap<int> heap;
  EXPECT_EQ(heap.size(), 0);
  EXPECT_TRUE(heap.empty());
}

TEST(Heap, test_public_insert_single_int) {
  RecordProperty(
      "expression",
      "Check that calling insert with a single value works as expected.");
  Heap<int> heap;
  heap.insert(-1);
  EXPECT_EQ(heap.size(), 1);
  EXPECT_FALSE(heap.empty());
  EXPECT_EQ(heap.peekMax(), -1);
}

TEST(Heap, test_public_size_correct_after_insert) {
  RecordProperty("expression",
                 "Check that inserting a value increments size each time.");
  Heap<int> heap;
  heap.insert(5);
  EXPECT_EQ(heap.size(), 1);
  heap.insert(4);
  EXPECT_EQ(heap.size(), 2);
  heap.insert(3);
  EXPECT_EQ(heap.size(), 3);
  heap.insert(2);
  EXPECT_EQ(heap.size(), 4);
  heap.insert(1);
  EXPECT_EQ(heap.size(), 5);
}

class HeapExtractTest : public testing::TestWithParam<vector<int>> {};

template <typename T>
vector<T> extract_all(Heap<T> &heap) {
  vector<T> elements;
  while (!heap.empty()) {
    elements.push_back(heap.extractMax());
  }
  return elements;
}

TEST_P(HeapExtractTest, test_public_extract_max) {
  RecordProperty(
      "expression",
      "Check that extract_max works correctly for various insertions.");
  Heap<int> heap;
  for (const auto v : GetParam()) {
    heap.insert(v);
  }
  vector<int> elements = extract_all(heap);
  vector<int> expected = GetParam();
  sort(expected.begin(), expected.end(), greater<int>());
  EXPECT_EQ(elements, expected);
}

TEST_P(HeapExtractTest, test_public_peek_max) {
  RecordProperty("expression",
                 "Check that peek_max works correctly for various insertions.");
  Heap<int> heap;
  for (const auto v : GetParam()) {
    heap.insert(v);
  }

  int last_max = heap.peekMax();
  EXPECT_EQ(last_max, heap.extractMax());
  while (!heap.empty()) {
    int max = heap.peekMax();
    EXPECT_EQ(max, heap.extractMax());
    EXPECT_GE(last_max, max);
    last_max = max;
  }
}

const vector<int> SAMPLE_VALUES{-17, -76, 52,  21,  -35, 66, 93,  83, 28,
                                -68, 99,  -27, -59, 23,  19, 100, 0};

INSTANTIATE_TEST_CASE_P(PublicTestValues, HeapExtractTest,
                        testing::Values(vector<int>{5}, vector<int>{3, 2, 1},
                                        vector<int>{5, 4, 3, 2, 1, 99},
                                        vector<int>{19, 0, -17, -76, -35, -68,
                                                    -27},
                                        SAMPLE_VALUES));                                   

class HeapKeysTest : public testing::TestWithParam<size_t> {};

TEST_P(HeapKeysTest, test_public_change_key) {
  Heap<int> heap;
  for (const auto v : SAMPLE_VALUES) {
    heap.insert(v);
  }
  heap.changeKey(SAMPLE_VALUES[GetParam()], -SAMPLE_VALUES[GetParam()]);
  auto elements = extract_all(heap);
  auto expected = SAMPLE_VALUES;
  expected[GetParam()] *= -1;
  sort(expected.begin(), expected.end(), greater<int>());
  EXPECT_EQ(elements, expected);
}

TEST_P(HeapKeysTest, test_public_delete) {
  Heap<int> heap;
  for (const auto v : SAMPLE_VALUES) {
    heap.insert(v);
  }
  heap.deleteItem(SAMPLE_VALUES[GetParam()]);
  auto elements = extract_all(heap);
  auto expected = SAMPLE_VALUES;
  expected.erase(expected.begin() + GetParam());
  sort(expected.begin(), expected.end(), greater<int>());
  EXPECT_EQ(elements, expected);
}

INSTANTIATE_TEST_CASE_P(PublicTestIndexValues, HeapKeysTest,
                        testing::Range((size_t)0, SAMPLE_VALUES.size()));
