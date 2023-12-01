#include "day01.hpp"

#include <gtest/gtest.h>

#include "common.hpp"

TEST(Day01Test, Problem1Example) {
  std::string input = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)";
  EXPECT_EQ(problem_1(input), 142);
}

TEST(Day01Test, Problem2Example) {
  std::string input = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";
  EXPECT_EQ(problem_2(input), 281);
}

TEST(Day01Test, Problem1) {
  std::string input = read_to_string("../data/day01.txt");
  ASSERT_NE(input.size(), 0);
  EXPECT_EQ(problem_1(input), 53194);
}

TEST(Day01Test, Problem2) {
  std::string input = read_to_string("../data/day01.txt");
  ASSERT_NE(input.size(), 0);
  EXPECT_EQ(problem_2(input), 54249);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
