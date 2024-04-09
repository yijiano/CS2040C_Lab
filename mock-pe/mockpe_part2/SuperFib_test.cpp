#include "SuperFib.cpp"
#include <gtest/gtest.h>
using namespace std;

TEST(SuperFibTest, test_public_base_cases)
{
    RecordProperty(
        "expression",
        "Check that superFib evaluates to the correct output for base cases.");
    EXPECT_EQ(superFib(0), 1);
    EXPECT_EQ(superFib(1), 1);
}

TEST(SuperFibTest, test_public_positive_integers)
{
    RecordProperty(
        "expression",
        "Check that superFib evaluates to the correct output for positive integers.");
    int expected = 1;
    for (int i = 2; i < 8; i++)
    {
        expected *= 2;
        EXPECT_EQ(superFib(i), expected);
    }
}

TEST(SuperFibTest, test_public_negative_integers)
{
    RecordProperty(
        "expression",
        "Check that superFib evaluates to the correct output for negative integers.");
    EXPECT_ANY_THROW(superFib(-1));
    EXPECT_ANY_THROW(superFib(-2));
}