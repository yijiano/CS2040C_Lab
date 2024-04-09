#include "caterpillar.cpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class CaterpillarTestInteger : public ::testing::TestWithParam<std::tuple<int, string>>
{
};

TEST_P(CaterpillarTestInteger, test_public_integer)
{
  RecordProperty("expression",
                 "Check that the function works as intended for input_1.");
  int input = std::get<0>(GetParam());
  string expected = std::get<1>(GetParam());
  EXPECT_EQ(caterpillar(input), expected);
}

INSTANTIATE_TEST_CASE_P(
    PublicTestValues,
    CaterpillarTestInteger,
    ::testing::Values(
        std::make_tuple(0, "<6"),
        std::make_tuple(1, "<Q6"),
        std::make_tuple(2, "<QQ6"),
        std::make_tuple(3, "<QQQ6"),
        std::make_tuple(4, "<QQQQ6"),
        std::make_tuple(5, "<QQQQQ6"),
        std::make_tuple(6, "<QQQQQQ6"),
        std::make_tuple(7, "<QQQQQQQ6"),
        std::make_tuple(8, "<QQQQQQQQ6"),
        std::make_tuple(9, "<QQQQQQQQQ6"),
        std::make_tuple(10, "<QQQQQQQQQQ6"),
        std::make_tuple(11, "<QQQQQQQQQQQ6"),
        std::make_tuple(12, "<QQQQQQQQQQQQ6"),
        std::make_tuple(13, "<QQQQQQQQQQQQQ6"),
        std::make_tuple(14, "<QQQQQQQQQQQQQQ6")));