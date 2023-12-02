#include <iostream>

#include "common.hpp"
#include "day02.hpp"

int main() {
  std::string input = read_to_string("data/day02.txt");
  std::cout << problem_1(input) << "\n" << problem_2(input) << "\n";
}
