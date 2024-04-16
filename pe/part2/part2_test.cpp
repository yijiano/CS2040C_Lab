#include "part2.h"
#include "part2.cpp"
#include <gtest/gtest.h>

#include <vector>

using namespace std;

#define IS_STATE 0
#define PF_STATE 1

void testArrayEqual(int *arr, vector<int> expected, int length) {
  // Helper Function to test if the array is equal to the expected vector
  vector<int> arrVec(arr, arr + length);
  EXPECT_EQ(arrVec, expected);
}

// [DOCUMENTATION] You should not need to understand or modify the following
// class to setup your own unit tests. (But it'd help to understand its setup())
class Part1Test : public ::testing::Test {
 protected:
  class SorterTest : public Sorter {
   public:
    int _step = 0;
    vector<int> _expected_indexes;
    vector<vector<int>> _expected_states;
    vector<int> _internalStates;

    /**
     * @brief Called to set the expected calls to insertionSort or
     * partition_first.
     *
     * @param expected_indexes The expected index values for internal state
     * calls.
     * @param expected_states The expected state values for comparison with
     * calls.
     */
    void setup(vector<int> expected_indexes,
               vector<vector<int>> expected_states) {
      _step = 0;
      // [NOTE] _expected_indexes contains the expected indexes of the newly
      // slotted or pivot (Depending on insertionSort or partition_first
      // respectively)
      _expected_indexes = expected_indexes;
      // [NOTE] _expected_states contains the expected states of the array after
      // each run of insertionSort or partition_first
      _expected_states = expected_states;
      _internalStates = {};
    }

   protected:
    void insertionSort_Step(int *arr, int start, int end,
                            int slotIndex) override {
      EXPECT_LT(_step, _expected_indexes.size());
      // Prevents out-of-bounds access
      if (_step >= _expected_indexes.size()) return;
      EXPECT_EQ(_expected_indexes[_step], slotIndex);
      testArrayEqual(arr + start, _expected_states[_step], end - start);
      _internalStates.push_back(IS_STATE);
      ++_step;
    }
    void parition_first_Step(int *arr, int start, int end,
                             int pivotIndex) override {
      EXPECT_LT(_step, _expected_indexes.size());
      // Prevents out-of-bounds access
      if (_step >= _expected_indexes.size()) return;
      EXPECT_EQ(_expected_indexes[_step], pivotIndex);
      testArrayEqual(arr + start, _expected_states[_step], end - start);
      _internalStates.push_back(PF_STATE);
      ++_step;
    }
  };
};

// [DOCUMENTATION] If you only want to create your own unit test to check for
// the final array without checking for the accurate step call, you can use the
// following test setup.
// TEST(Part1SimpleTest, test_public_insertion_noStepCheck) {
//   RecordProperty("expression",
//                  "Only to ensure that the final arr is correct without "
//                  "checking for accurate step.");

//   int arr[5] = {5, 8, 2, 9, 4};
//   Sorter sorter;
//   sorter.insertionSort(arr, 0, 5);
//   testArrayEqual(arr, {2, 4, 5, 8, 9}, 5);
// }

// // [DOCUMENTATION] The following test will contain comments to help explain how
// // to setup your own unit tests. Reminder to use TEST_F(Part1SimpleTest,
// // test_name) instead of TEST() for testing insertionSort() and
// // partition_first()
// TEST_F(Part1Test, test_public_insertion_question_example_1) {
//   RecordProperty("expression",
//                  "Check that the insertionSort() works as intended as per the "
//                  "Question Example.");

//   // Create an instance of SorterTest
//   SorterTest sorter;
//   // Create an array to test the insertionSort() function
//   int arr[15] = {12, 14, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 1, 4, 13};
//   // Setup the expected indexes and states of the array after each run of
//   // insertionSort() - Ensure setup() whenever there's a step func call.
//   // [NOTE] The expected indexes [1st parameter] contains the order of indexes
//   // of the newly slotted item
//   // [NOTE] The expected states [2nd parameter] contains the states of the array
//   // after each run
//   sorter.setup({1, 0, 0, 2, 3, 2, 2, 6, 0},
//                {{12, 14, 5, 3, 9, 10, 7, 6, 11, 2},
//                 {5, 12, 14, 3, 9, 10, 7, 6, 11, 2},
//                 {3, 5, 12, 14, 9, 10, 7, 6, 11, 2},
//                 {3, 5, 9, 12, 14, 10, 7, 6, 11, 2},
//                 {3, 5, 9, 10, 12, 14, 7, 6, 11, 2},
//                 {3, 5, 7, 9, 10, 12, 14, 6, 11, 2},
//                 {3, 5, 6, 7, 9, 10, 12, 14, 11, 2},
//                 {3, 5, 6, 7, 9, 10, 11, 12, 14, 2},
//                 {2, 3, 5, 6, 7, 9, 10, 11, 12, 14}});
//   // Call the insertionSort() function with your parameters
//   sorter.insertionSort(arr, 0, 10);
//   // Check if the number of steps is correct (Number of runs [n-1])
//   EXPECT_EQ(9, sorter._step);
//   // Check if the full final array is equal to the expected array
//   testArrayEqual(arr, {2, 3, 5, 6, 7, 9, 10, 11, 12, 14, 0, 8, 1, 4, 13}, 15);
// }

// TEST_F(Part1Test, test_public_insertion_question_example_2) {
//   RecordProperty("expression",
//                  "Check that the insertionSort() works as intended as per the "
//                  "Question Example.");

//   SorterTest sorter;
//   int arr[15] = {12, 14, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 1, 4, 13};
//   sorter.setup({4, 5, 4, 4, 8, 3}, {{3, 9, 10, 7, 6, 11, 2},
//                                     {3, 9, 10, 7, 6, 11, 2},
//                                     {3, 7, 9, 10, 6, 11, 2},
//                                     {3, 6, 7, 9, 10, 11, 2},
//                                     {3, 6, 7, 9, 10, 11, 2},
//                                     {2, 3, 6, 7, 9, 10, 11}});
//   sorter.insertionSort(arr, 3, 10);
//   EXPECT_EQ(6, sorter._step);
//   testArrayEqual(arr, {12, 14, 5, 2, 3, 6, 7, 9, 10, 11, 0, 8, 1, 4, 13}, 15);
// }

// TEST_F(Part1Test, test_public_insertion_empty_array) {
//   RecordProperty(
//       "expression",
//       "Check that the insertionSort() works on empty array without crashing.");

//   SorterTest sorter;
//   int *arr = {};
//   sorter.insertionSort(arr, 0, 0);
//   EXPECT_EQ(0, sorter._step);
// }

// TEST_F(Part1Test, test_public_insertion_single_element_array) {
//   RecordProperty("expression",
//                  "Check that the insertionSort() works on single element array "
//                  "without any unnecessary runs.");

//   SorterTest sorter;
//   int arr[1] = {8};
//   sorter.insertionSort(arr, 0, 1);
//   EXPECT_EQ(0, sorter._step);
//   testArrayEqual(arr, {8}, 1);
// }

// TEST_F(Part1Test, test_public_insertion_two_element_array) {
//   RecordProperty(
//       "expression",
//       "Check that the insertionSort() works correctly on two element array.");

//   SorterTest sorter;
//   int arr[2] = {0, 1};
//   sorter.setup({1}, {{0, 1}});
//   sorter.insertionSort(arr, 0, 2);
//   EXPECT_EQ(1, sorter._step);
//   testArrayEqual(arr, {0, 1}, 2);
// }

// Feel free to add more unit tests here...

TEST_F(Part1Test, test_public_parition_question_example_1) {
  RecordProperty(
      "expression",
      "Check that the partition_first() works as intended as per the "
      "Question Example.");

  SorterTest sorter;
  int arr[15] = {12, 14, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 1, 4, 13};
  sorter.setup({12}, {{1, 4, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 12, 14, 13}});
  sorter.partition_first(arr, 0, 15);
  EXPECT_EQ(1, sorter._step);
  testArrayEqual(arr, {1, 4, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 12, 14, 13}, 15);
}

TEST_F(Part1Test, test_public_parition_question_example_2) {
  RecordProperty(
      "expression",
      "Check that the partition_first() works as intended as per the "
      "Question Example.");

  SorterTest sorter;
  int arr[15] = {12, 14, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 1, 4, 13};
  sorter.setup({9}, {{2, 8, 7, 6, 0, 9, 11, 10}});
  sorter.partition_first(arr, 4, 12);
  EXPECT_EQ(1, sorter._step);
  testArrayEqual(arr, {12, 14, 5, 3, 2, 8, 7, 6, 0, 9, 11, 10, 1, 4, 13}, 15);
}

TEST_F(Part1Test, test_public_parition_empty_array) {
  RecordProperty(
      "expression",
      "Check that the insertionSort() works on empty array without crashing.");

  SorterTest sorter;
  int *arr = {};
  sorter.partition_first(arr, 0, 0);
  EXPECT_EQ(0, sorter._step);
}

TEST_F(Part1Test, test_public_parition_single_element_array) {
  RecordProperty(
      "expression",
      "Check that the partition_first() works on single element array "
      "without any unnecessary runs.");

  SorterTest sorter;
  int arr[1] = {8};
  sorter.partition_first(arr, 0, 1);
  EXPECT_EQ(0, sorter._step);
  testArrayEqual(arr, {8}, 1);
}

TEST_F(Part1Test, test_public_parition_two_element_array) {
  RecordProperty(
      "expression",
      "Check that the partition_first() works correctly on two element array.");

  SorterTest sorter;
  int arr[2] = {0, 1};
  sorter.setup({0}, {{0, 1}});
  sorter.partition_first(arr, 0, 2);
  EXPECT_EQ(1, sorter._step);
  testArrayEqual(arr, {0, 1}, 2);
}

// Feel free to add more unit tests here...

TEST_F(Part1Test, test_public_quickSort_question_example) {
  RecordProperty("expression",
                 "Check that the quickSort() works as intended as per the "
                 "Question Example.");

  SorterTest sorter;
  int arr[15] = {12, 14, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 1, 4, 13};
  sorter.setup({12, 1, 5, 3, 4, 7, 11, 9, 9, 13},
               {{1, 4, 5, 3, 9, 10, 7, 6, 11, 2, 0, 8, 12, 14, 13},
                {0, 1, 5, 3, 9, 10, 7, 6, 11, 2, 4, 8},
                {2, 3, 4, 5, 7, 6, 11, 10, 9, 8},
                {2, 3, 4},
                {2, 3, 4},
                {6, 7, 11, 10, 9, 8},
                {8, 10, 9, 11},
                {8, 10, 9},
                {8, 9, 10},
                {13, 14}});
  sorter.quickSort(arr, 0, 15, 3);
  EXPECT_EQ(10, sorter._step);
  testArrayEqual(arr, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 15);
  vector<int> expectedStates = {PF_STATE, PF_STATE, PF_STATE, IS_STATE,
                                IS_STATE, PF_STATE, PF_STATE, IS_STATE,
                                IS_STATE, IS_STATE};
  EXPECT_EQ(expectedStates, sorter._internalStates);
}

TEST_F(Part1Test, test_public_quickSort_simple) {
  RecordProperty("expression",
                 "Check that the quickSort() works as intended as per the "
                 "Question Example.");

  SorterTest sorter;
  int arr[15] = {3, 2, 0, 1, 5, 4};
  sorter.setup({3, 1, 4}, {{1, 2, 0, 3, 5, 4}, {0, 1, 2}, {4, 5}});
  sorter.quickSort(arr, 0, 6, 2);
  EXPECT_EQ(3, sorter._step);
  testArrayEqual(arr, {0, 1, 2, 3, 4, 5}, 6);
  // For this unit test, the quickSort algorithm will first partition the first
  // element of the array, splitting into {0,1,2} and {4,5} respectively.
  // As a result, {0,1,2} will be passed onto another partition while {4,5} will
  // be passed onto insertionSort. Therefore, expectedStates is as follows...

  // Partition: 1 2 0 (3) 5 4
  // Partition: 0 (1) 2
  // Insertion: 4 5
  vector<int> expectedStates = {PF_STATE, PF_STATE, IS_STATE};
  EXPECT_EQ(expectedStates, sorter._internalStates);
}

TEST_F(Part1Test, test_public_quickSort_empty_array) {
  RecordProperty(
      "expression",
      "Check that the quickSort() works on empty array without crashing.");

  SorterTest sorter;
  int *arr = {};
  sorter.quickSort(arr, 0, 0);
  EXPECT_EQ(0, sorter._step);
}

TEST_F(Part1Test, test_public_quickSort_single_element_array) {
  RecordProperty("expression",
                 "Check that the quickSort() works on single element array "
                 "without any unnecessary runs.");

  SorterTest sorter;
  int arr[1] = {8};
  sorter.quickSort(arr, 0, 1);
  EXPECT_EQ(0, sorter._step);
  testArrayEqual(arr, {8}, 1);
}

TEST_F(Part1Test, test_public_quickSort_two_element_array) {
  RecordProperty(
      "expression",
      "Check that the quickSort() works correctly on two element array.");

  SorterTest sorter;
  int arr[2] = {0, 1};
  sorter.setup({0}, {{0, 1}});
  sorter.quickSort(arr, 0, 2);
  EXPECT_EQ(1, sorter._step);
  testArrayEqual(arr, {0, 1}, 2);
  vector<int> expectedStates = {PF_STATE};
  EXPECT_EQ(expectedStates, sorter._internalStates);
}

// Feel free to add more unit tests here...
