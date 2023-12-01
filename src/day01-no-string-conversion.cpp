#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

#include "day01.hpp"

std::vector<std::string> split(std::string const &string, char delimiter) {
  std::vector<std::string> lines;
  size_t start = 0;
  for (size_t i = 0; i < string.size(); ++i) {
    char c = string[i];
    if (c == delimiter) {
      lines.push_back(string.substr(start, i - start));
      start = i + 1;
    }
  }
  lines.push_back(string.substr(start, string.size() - start));

  return lines;
}

std::vector<char> filter(std::string const &string,
                         bool (*predicate)(char const &c)) {
  std::vector<char> result;
  for (char const &c : string) {
    if (predicate(c)) {
      result.push_back(c);
    }
  }
  return result;
}

size_t problem_1(std::string const &input) {
  size_t sum = 0;
  for (auto const &line : split(input, '\n')) {
    if (line.empty()) {
      continue;
    }

    auto digits = filter(
        line, [](char const &c) -> bool { return std::isdigit(c) == 1; });
    sum += (digits.front() - '0') * 10 + (digits.back() - '0');
  }

  return sum;
}

std::unordered_map<std::string, char> digit_in_letters = {
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'},
};

size_t problem_2(std::string const &input) {
  size_t sum = 0;
  for (auto const &line : split(input, '\n')) {
    if (line.empty()) {
      continue;
    }
    std::vector<char> digits;
    for (size_t i = 0; i < line.size(); ++i) {
      if (std::isdigit(line[i]) == 1) {
        digits.push_back(line[i]);
        continue;
      }

      for (auto const &[letters, c] : digit_in_letters) {
        if (line.substr(i, letters.size()) == letters) {
          digits.push_back(c);
        }
      }
    }

    sum += (digits.front() - '0') * 10 + (digits.back() - '0');
  }

  return sum;
}
