project('advent-of-code', 'cpp',
  default_options: [
    'warning_level=3',
    'werror=true',
    'cpp_std=c++20',
    'cpp_eh=none',
    'cpp_rtti=false',
    'cpp_args=-Wold-style-cast -Wconversion -Wsign-conversion',
  ],
)

gtest_dep = dependency('gtest')

inc = include_directories('include')

executable('day01-naive',
  sources: ['src/common.cpp', 'src/day01.cpp', 'src/day01-naive.cpp'],
  include_directories: inc,
)

day01_naive_test = executable('test-day01-naive',
  sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01-naive.cpp'],
  include_directories: inc,
  dependencies: [gtest_dep],
)

test('test day01-naive', day01_naive_test)

executable('day01-no-string-conversion',
  sources: ['src/common.cpp', 'src/day01.cpp', 'src/day01-no-string-conversion.cpp'],
  include_directories: inc,
)

day01_no_string_conversion_test = executable('test-day01-no-string-conversion',
  sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01-no-string-conversion.cpp'],
  include_directories: inc,
  dependencies: [gtest_dep],
)

test('test day01-no-string-conversion', day01_no_string_conversion_test)

executable('day01-no-split',
  sources: ['src/common.cpp', 'src/day01.cpp', 'src/day01-no-split.cpp'],
  include_directories: inc,
)

day01_no_split_test = executable('test-day01-no-split',
  sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01-no-split.cpp'],
  include_directories: inc,
  dependencies: [gtest_dep],
)

test('test day01-no-split', day01_no_split_test)

executable('day01-array-over-map',
  sources: ['src/common.cpp', 'src/day01.cpp', 'src/day01-array-over-map.cpp'],
  include_directories: inc,
)

day01_array_over_map_test = executable('test-day01-array-over-map',
  sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01-array-over-map.cpp'],
  include_directories: inc,
  dependencies: [gtest_dep],
)

test('test day01-array-over-map', day01_array_over_map_test)
