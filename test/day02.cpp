#include "day02.hpp"

#include <gtest/gtest.h>

#include "common.hpp"

TEST(Day02, Problem1Example) {
  std::string input = R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)";
  EXPECT_EQ(problem_1(input), 8);
}

TEST(Day02, Problem1) {
  std::string input = read_to_string("../data/day02.txt");
  EXPECT_EQ(problem_1(input), 2268);
}

TEST(Day02, Problem2Example) {
  std::string input = R"(Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green)";
  EXPECT_EQ(problem_2(input), 2286);
}

TEST(Day02, Problem2) {
  std::string input = read_to_string("../data/day02.txt");
  EXPECT_EQ(problem_2(input), 63542);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
