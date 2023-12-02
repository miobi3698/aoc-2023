#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "day02.hpp"

std::vector<std::string_view> split(std::string_view input,
                                    std::string_view delimiter) {
  std::vector<std::string_view> result;
  size_t start = 0;
  for (size_t i = 0; i < input.size(); ++i) {
    if (std::string_view(&input[i], delimiter.size()) == delimiter) {
      result.emplace_back(&input[start], i - start);
      start = i + delimiter.size();
    }
  }

  result.emplace_back(&input[start], input.size() - start);
  return result;
}

std::pair<std::string_view, std::string_view> split_into_two(
    std::string_view input, std::string_view delimiter) {
  size_t index = 0;
  for (size_t i = 0; i < input.size(); ++i) {
    if (std::string_view(&input[i], delimiter.size()) == delimiter) {
      index = i;
      break;
    }
  }
  return std::make_pair(
      std::string_view(input.data(), index),
      std::string_view(&input[index + delimiter.size()],
                       input.size() - index - delimiter.size()));
}

size_t problem_1(std::string_view input) {
  size_t sum = 0;

  auto lines = split(input, "\n");
  for (auto const &line : lines) {
    if (line.empty()) {
      continue;
    }

    std::string_view game_str;
    std::string_view sets;
    std::tie(game_str, sets) = split_into_two(line, ": ");
    std::string_view id_str;
    std::tie(std::ignore, id_str) = split_into_two(game_str, " ");
    auto const set_list = split(sets, "; ");
    int id = std::stoi(std::string(id_str));
    bool is_valid = true;
    for (auto const set : set_list) {
      auto const cubes = split(set, ", ");
      for (auto const &cube : cubes) {
        std::string_view count_str;
        std::string_view color;
        std::tie(count_str, color) = split_into_two(cube, " ");
        int count = std::stoi(std::string(count_str));
        if ((color == "red" && count > 12) ||
            (color == "green" && count > 13) ||
            (color == "blue" && count > 14)) {
          is_valid = false;
        }
      }
    }

    if (is_valid) {
      sum += id;
    }
  }

  return sum;
}

template <typename T>
T max(T const &a, T const &b) {
  return a > b ? a : b;
}

size_t problem_2(std::string_view input) {
  size_t sum = 0;

  auto lines = split(input, "\n");
  for (auto const &line : lines) {
    if (line.empty()) {
      continue;
    }

    std::string_view sets;
    std::tie(std::ignore, sets) = split_into_two(line, ": ");
    auto const set_list = split(sets, "; ");
    bool is_valid = true;
    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;
    for (auto const set : set_list) {
      auto const cubes = split(set, ", ");
      for (auto const &cube : cubes) {
        std::string_view count_str;
        std::string_view color;
        std::tie(count_str, color) = split_into_two(cube, " ");
        int count = std::stoi(std::string(count_str));
        if (color == "red") {
          max_red = max(max_red, count);
        } else if (color == "green") {
          max_green = max(max_green, count);
        } else if (color == "blue") {
          max_blue = max(max_blue, count);
        }
      }
    }

    if (is_valid) {
      sum += static_cast<size_t>(max_red) * max_green * max_blue;
    }
  }

  return sum;
}
