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

days = {
  'day01': [
    'naive',
    'no-string-conversion',
    'no-split',
    'array-over-map',
    'better-letters-check',
    'remove-digits-list',
  ],
  'day02': [
    'naive',
  ],
}

foreach day, impls : days
  foreach impl : impls
    executable(day + '-' + impl,
      sources: ['src/common.cpp', 'src/' + day + '/main.cpp', 'src/' + day + '/' + impl +'.cpp'],
      include_directories: inc,
      override_options: [
        'buidtype=release',
      ]
    )

    test('test ' + day + '-' + impl,
      executable('test-' + day + '-' + impl,
        sources: ['src/common.cpp', 'test/' + day + '.cpp', 'src/' + day + '/' + impl + '.cpp'],
        include_directories: inc,
        dependencies: [gtest_dep],
      ),
      suite: day,
      protocol: 'gtest')
  endforeach
endforeach

