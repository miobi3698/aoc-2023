#include "day01.hpp"

#include <iostream>
#include <string>

#include "common.hpp"

int main() {
  std::string input = read_to_string("data/day01.txt");
  std::cout << problem_1(input) << "\n" << problem_2(input) << "\n";
  return 0;
}
