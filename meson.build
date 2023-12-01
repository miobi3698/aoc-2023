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

gtest_dep = dependency('gtest', include_type: 'system')

inc = include_directories('include')

day01_impls = ['naive', 'no-string-conversion', 'no-split', 'array-over-map', 'better-letters-check']

foreach impl : day01_impls
  executable('day01-' + impl,
    sources: ['src/common.cpp', 'src/day01/main.cpp', 'src/day01/' + impl +'.cpp'],
    include_directories: inc,
    override_options: [
      'buidtype=release',
    ]
  )

  test('test day01-' + impl,
    executable('test-day01-' + impl,
      sources: ['src/common.cpp', 'test/day01.cpp', 'src/day01/' + impl + '.cpp'],
      include_directories: inc,
      dependencies: [gtest_dep],
    ),
    suite: 'day01',
    protocol: 'gtest')
endforeach

