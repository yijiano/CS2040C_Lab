#include "linked_list.h"
#include <gtest/gtest.h>
#include <vector>

const std::initializer_list<int> SAMPLE_INTS{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};

TEST(List, test_public_default_constructor) {
  List<int> list{};
  EXPECT_EQ(list.size(), 0);
}

TEST(List, test_public_empty_int) {
  List<int> list1{};
  EXPECT_EQ(list1.empty(), true);

  List<int> list2{0};
  EXPECT_EQ(list2.empty(), false);
}

TEST(List, test_public_push_head_int) {
  List<int> list;
  EXPECT_EQ(list.size(), 0);

  int i = 0;
  for (auto it = SAMPLE_INTS.begin(); it != SAMPLE_INTS.end(); it++) {
    list.push_head(*it);
    EXPECT_EQ(list.size(), ++i);
    EXPECT_EQ(list.head(), *it);
  }
}

TEST(List, test_public_pop_head_int) {
  List<int> list(SAMPLE_INTS);

  int i = SAMPLE_INTS.size();
  for (auto it = SAMPLE_INTS.begin(); it != SAMPLE_INTS.end(); it++) {
    EXPECT_EQ(list.size(), i--);
    EXPECT_EQ(list.head(), *it);
    list.pop_head();
  }

  EXPECT_EQ(list.size(), 0);
}

TEST(List, test_public_contains_int) {
  List<int> list(SAMPLE_INTS);
  EXPECT_TRUE(list.contains(9));
  EXPECT_FALSE(list.contains(-1));
}

TEST(List, test_public_extract_max_int) {
  List<int> list(SAMPLE_INTS);
  EXPECT_EQ(list.extract_max(), 9);
}

TEST(list, test_append) {
  List<int> list(SAMPLE_INTS);
  EXPECT_EQ(list.size(), SAMPLE_INTS.size());
  list.append_tail(999);
  EXPECT_EQ(list.size(), SAMPLE_INTS.size() + 1);
  EXPECT_TRUE(list.contains(999));
}

TEST(List, test_public_reverse_int) {
  List<int> list(SAMPLE_INTS);
  list.reverse();

  int i = SAMPLE_INTS.size();
  auto it = SAMPLE_INTS.end();
  while (--it != SAMPLE_INTS.begin()) {
    EXPECT_EQ(list.size(), i--);
    EXPECT_EQ(list.head(), *it);
    list.pop_head();
  }
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.head(), *it);
}

TEST(List, test_public_to_string_empty) {
  List<int> list{};
  EXPECT_EQ(list.to_string(), "{}");
}

TEST(List, test_public_to_string_int) {
  List<int> list(SAMPLE_INTS);
  EXPECT_EQ(list.to_string(),
            "{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3}");
}
