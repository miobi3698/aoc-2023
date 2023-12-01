#include "common.hpp"

#include <fstream>
#include <iterator>

std::string read_to_string(std::filesystem::path const &path) {
  std::ifstream file_stream(path);
  return {std::istreambuf_iterator<char>(file_stream), {}};
}
