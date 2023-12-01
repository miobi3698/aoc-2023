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

executable('day01',
  sources: ['src/common.cpp', 'src/day01.cpp', 'src/day01-naive.cpp'],
  include_directories: inc,
)

day01_test = executable('test-day01-naive',
  sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01-naive.cpp'],
  include_directories: inc,
  dependencies: [gtest_dep],
)

test('test day01-naive', day01_test)