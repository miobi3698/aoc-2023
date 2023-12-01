#include <array>
#include <cctype>
#include <string>
#include <string_view>
#include <utility>

#include "day01.hpp"

size_t problem_1(std::string const &input) {
  size_t sum = 0;
  char digits[2];
  bool is_start = true;

  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '\n' || i + 1 == input.size()) {
      sum += (digits[0] - '0') * 10 + (digits[1] - '0');
      is_start = true;
    } else {
      if (std::isdigit(input[i]) == 1) {
        if (is_start) {
          digits[0] = input[i];
          is_start = false;
        }

        digits[1] = input[i];
      }
    }
  }

  return sum;
}

constexpr std::array<std::pair<std::string_view, char>, 9> digit_in_letters = {
    std::make_pair("one", '1'),   std::make_pair("two", '2'),
    std::make_pair("three", '3'), std::make_pair("four", '4'),
    std::make_pair("five", '5'),  std::make_pair("six", '6'),
    std::make_pair("seven", '7'), std::make_pair("eight", '8'),
    std::make_pair("nine", '9'),
};

size_t problem_2(std::string const &input) {
  size_t sum = 0;
  char digits[2];
  bool is_start = true;

  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '\n' || i + 1 == input.size()) {
      sum += (digits[0] - '0') * 10 + (digits[1] - '0');
      is_start = true;
    } else {
      if (std::isdigit(input[i]) == 1) {
        if (is_start) {
          digits[0] = input[i];
          is_start = false;
        }

        digits[1] = input[i];
        continue;
      }

      for (auto const &[letters, c] : digit_in_letters) {
        std::string_view view(&input[i], letters.size());
        if (view[0] == letters[0] && view == letters) {
          if (is_start) {
            digits[0] = c;
            is_start = false;
          }

          digits[1] = c;
          break;
        }
      }
    }
  }

  return sum;
}
