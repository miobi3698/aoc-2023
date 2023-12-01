#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

#include "day01.hpp"

size_t problem_1(std::string const &input) {
  size_t sum = 0;
  std::vector<char> digits;

  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '\n' || i + 1 == input.size()) {
      sum += (digits.front() - '0') * 10 + (digits.back() - '0');
      digits.clear();
    } else {
      if (std::isdigit(input[i]) == 1) {
        digits.push_back(input[i]);
      }
    }
  }

  return sum;
}

std::unordered_map<std::string, char> digit_in_letters = {
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'},
};

size_t problem_2(std::string const &input) {
  size_t sum = 0;
  std::vector<char> digits;

  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '\n' || i + 1 == input.size()) {
      sum += (digits.front() - '0') * 10 + (digits.back() - '0');
      digits.clear();
    } else {
      if (std::isdigit(input[i]) == 1) {
        digits.push_back(input[i]);
        continue;
      }

      for (auto const &[letters, c] : digit_in_letters) {
        if (input.substr(i, letters.size()) == letters) {
          digits.push_back(c);
        }
      }
    }
  }

  return sum;
}
