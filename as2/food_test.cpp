#include "food.h"
#include <gtest/gtest.h>
#include <vector>

const Food salad("Salad", 100);
const Food chicken("Chicken", 200);
const Food sm_curry("Curry", 40);
const Food lg_curry("Curry", 1000);

TEST(Food, test_public_chicken_salad_name) {
  EXPECT_EQ((chicken + salad).name(), "Chicken Salad");
}

TEST(Food, test_public_chicken_salad_calories) {
  EXPECT_EQ((chicken + salad).calories(), 300);
}

TEST(Food, test_public_double_salad_name) {
  EXPECT_EQ((salad + salad).name(), "Salad Salad");
}

TEST(Food, test_public_double_salad_calories) {
  EXPECT_EQ((salad + salad).calories(), 200);
}

TEST(Food, test_public_salad_chicken_name) {
  EXPECT_EQ((salad + chicken).name(), "Salad Chicken");
}

TEST(Food, test_public_salad_chicken_calories) {
  EXPECT_EQ((salad + chicken).calories(), 300);
}

TEST(Food, test_public_curry_chicken_salad_name) {
  EXPECT_EQ((sm_curry + chicken + salad).name(), "Curry Chicken Salad");
}

TEST(Food, test_public_curry_chicken_salad_calories) {
  EXPECT_EQ((sm_curry + chicken + salad).calories(), 340);
}


TEST(Food, test_public_long_sum_name) {
  EXPECT_EQ((salad + lg_curry + salad + sm_curry + chicken + salad).name(),
    "Salad Curry Salad Curry Chicken Salad");
}

TEST(Food, test_public_long_sum_calories) {
  EXPECT_EQ((salad + lg_curry + salad + sm_curry + chicken + salad).calories(), 1540);
}
