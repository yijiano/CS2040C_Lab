#include "linked_list.h"
#include <gtest/gtest.h>
#include <vector>

namespace {
TEST(List, test_public_default_constructor) {
  List list{};
  EXPECT_EQ(list.size(), 0);
}

// TEST(List, test_public_init_list_constructor) {
//   std::vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};

//   List list{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};
//   ASSERT_EQ(list.size(), vec.size());

//   size_t idx = 0;
//   for (Node *node = list.head(); node != nullptr; node = node->next) {
//     EXPECT_EQ(node->element, vec.at(idx++));
//   }
// }

TEST(List, test_public_empty) {
  List list1{};
  EXPECT_EQ(list1.empty(), true);

  List list2{0};
  EXPECT_EQ(list2.empty(), false);
}

TEST(List, test_public_push_head) {
  std::vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};

  List list{};

  EXPECT_EQ(list.size(), 0);

  for (size_t idx = 0; idx < vec.size(); idx++) {
    list.push_head(vec.at(idx));
    EXPECT_EQ(list.size(), idx + 1);
    EXPECT_EQ(list.head(), vec.at(idx));
  }
}

TEST(List, test_public_pop_head) {
  std::vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};

  List list{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};

  for (size_t idx = 0; idx < vec.size(); idx++) {
    EXPECT_EQ(list.size(), vec.size() - idx);
    EXPECT_EQ(list.head(), vec.at(idx));
    EXPECT_EQ(list.pop_head(), vec.at(idx));
  }

  EXPECT_EQ(list.size(), 0);
}

TEST(List, test_public_contains) {
  List list{0, 2, 4, 6, 8};

  for (int elem = 0; elem < 10; elem++) {
    EXPECT_EQ(list.contains(elem), elem % 2 == 0);
  }
}

TEST(List, test_public_to_string_01) {
  List list{};
  EXPECT_EQ(list.to_string(), "{}");
}

TEST(List, test_public_to_string_02) {
  List list{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};
  EXPECT_EQ(list.to_string(),
            "{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3}");
}
} // namespace