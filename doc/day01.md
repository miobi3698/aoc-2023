# Day 01

## Problem

### Problem 1

Your are given a string consist of lines.
Each line have digits and ascii characters.
Collect the first and last digit to form a 2 digit number.
Then calculate the sum of it.

### Solution 1 - Naive way

Split the input into lines.
Filter the line to for a digit list.
Pick the first and last digit to for a number string.
Convert the string to number.
Sum all of the numbers.

### Problem 2

Same as the problem 1 but some of the digits are spelled out with letters.
- `one`
- `two`
- `three`
- `four`
- `five`
- `six`
- `seven`
- `eight`
- `nine`

### Solution 2 - Naive way

Split the input into lines.
Filter the digits or digit letters to for a number list.
Pick the first and last digit to for a number string.
Convert the string to number.
Sum all of the numbers.

## Optimisation

### Optimisation 1 - No string conversion

Instead of create a string from first and last digit then convert to number, calculate the number by:
- Convert the digit to number
- number = first * 10 + second

```bash
$ hyperfine --warmup 3 ./build/day01-naive ./build/day01-no-string-conversion
Benchmark 1: ./build/day01-naive
  Time (mean ± σ):      15.2 ms ±   1.0 ms    [User: 14.5 ms, System: 0.9 ms]
  Range (min … max):    14.0 ms …  20.2 ms    190 runs

Benchmark 2: ./build/day01-no-string-conversion
  Time (mean ± σ):      14.7 ms ±   0.9 ms    [User: 14.1 ms, System: 0.9 ms]
  Range (min … max):    13.4 ms …  18.6 ms    185 runs

Summary
  ./build/day01-no-string-conversion ran
    1.03 ± 0.09 times faster than ./build/day01-naive
```

### Optimisation 2 - No split

Instead of splitting the input into lines, iterate on the input string directly then:
- If it is a digit, add to to the digit list
- On newline or end of string, clear digit list
- Calculate the number
- Add it to the sum

```bash
$ hyperfine --warmup 3 ./build/day01-naive ./build/day01-no-string-conversion ./build/day01-no-split
Benchmark 1: ./build/day01-naive
  Time (mean ± σ):      15.4 ms ±   0.8 ms    [User: 14.6 ms, System: 1.0 ms]
  Range (min … max):    14.4 ms …  19.8 ms    177 runs

Benchmark 2: ./build/day01-no-string-conversion
  Time (mean ± σ):      15.2 ms ±   1.1 ms    [User: 14.1 ms, System: 1.3 ms]
  Range (min … max):    14.0 ms …  20.0 ms    178 runs

Benchmark 3: ./build/day01-no-split
  Time (mean ± σ):      14.2 ms ±   0.9 ms    [User: 13.6 ms, System: 0.9 ms]
  Range (min … max):    13.1 ms …  18.8 ms    206 runs

Summary
  ./build/day01-no-split ran
    1.07 ± 0.10 times faster than ./build/day01-no-string-conversion
    1.08 ± 0.09 times faster than ./build/day01-naive
```

### Optimisation 3 - Array over map

For problem 2, swap out the map of digit letters to using array to:
- Avoid runtime construction of map, can create array in constexpr
- We iterate over the map anyway so no need to pay for lookup

```bash
$ hyperfine --warmup 10 ./build/day01-naive ./build/day01-no-string-conversion ./build/day01-no-split ./build/day01-array-over-map
Benchmark 1: ./build/day01-naive
  Time (mean ± σ):      15.4 ms ±   1.2 ms    [User: 14.5 ms, System: 1.1 ms]
  Range (min … max):    14.1 ms …  20.5 ms    183 runs

Benchmark 2: ./build/day01-no-string-conversion
  Time (mean ± σ):      14.9 ms ±   1.1 ms    [User: 14.2 ms, System: 1.0 ms]
  Range (min … max):    13.6 ms …  18.7 ms    184 runs

Benchmark 3: ./build/day01-no-split
  Time (mean ± σ):      14.2 ms ±   1.1 ms    [User: 13.6 ms, System: 0.9 ms]
  Range (min … max):    12.7 ms …  18.8 ms    189 runs

Benchmark 4: ./build/day01-array-over-map
  Time (mean ± σ):       8.9 ms ±   1.0 ms    [User: 8.3 ms, System: 0.8 ms]
  Range (min … max):     7.7 ms …  12.8 ms    315 runs

Summary
  ./build/day01-array-over-map ran
    1.61 ± 0.22 times faster than ./build/day01-no-split
    1.69 ± 0.23 times faster than ./build/day01-no-string-conversion
    1.74 ± 0.24 times faster than ./build/day01-naive
```

### Optimisation 4 - Better letters check

For problem 2, we can reduce the cost of digits letters checks by:
- Replace substr with string_view, substr construct a new string but we only need to do comparison
- Check for first letter first before going with full string check

```bash
$ hyperfine --warmup 10 --shell=none ./build/day01-naive ./build/day01-no-string-conversion ./build/day01-no-split ./build/day01-array-over-map ./build/day01-better-letters-check
Benchmark 1: ./build/day01-naive
  Time (mean ± σ):      16.2 ms ±   1.7 ms    [User: 14.8 ms, System: 1.3 ms]
  Range (min … max):    14.8 ms …  27.1 ms    174 runs

Benchmark 2: ./build/day01-no-string-conversion
  Time (mean ± σ):      15.4 ms ±   2.0 ms    [User: 14.6 ms, System: 0.7 ms]
  Range (min … max):    13.6 ms …  27.0 ms    212 runs

Benchmark 3: ./build/day01-no-split
  Time (mean ± σ):      14.2 ms ±   1.4 ms    [User: 13.4 ms, System: 0.7 ms]
  Range (min … max):    12.6 ms …  23.6 ms    227 runs

Benchmark 4: ./build/day01-array-over-map
  Time (mean ± σ):       8.9 ms ±   1.0 ms    [User: 8.2 ms, System: 0.7 ms]
  Range (min … max):     8.2 ms …  13.8 ms    229 runs

Benchmark 5: ./build/day01-better-letters-check
  Time (mean ± σ):       5.1 ms ±   0.7 ms    [User: 4.5 ms, System: 0.5 ms]
  Range (min … max):     4.8 ms …   9.7 ms    601 runs

Summary
  ./build/day01-better-letters-check ran
    1.74 ± 0.30 times faster than ./build/day01-array-over-map
    2.78 ± 0.45 times faster than ./build/day01-no-split
    3.00 ± 0.55 times faster than ./build/day01-no-string-conversion
    3.17 ± 0.53 times faster than ./build/day01-naive
```

### Optimisation 5 - Remove digits list

We only need the first and last digits, not the whole list
```bash
$ hyperfine --warmup 10 --shell=none ./build/day01-naive ./build/day01-no-string-conversion ./build/day01-no-split ./build/day01-array-over-map ./build/day01-better-letters-check ./build/day01-remove-digits-list
Benchmark 1: ./build/day01-naive
  Time (mean ± σ):      16.1 ms ±   1.8 ms    [User: 15.0 ms, System: 1.0 ms]
  Range (min … max):    14.6 ms …  30.5 ms    205 runs

Benchmark 2: ./build/day01-no-string-conversion
  Time (mean ± σ):      15.5 ms ±   2.5 ms    [User: 14.5 ms, System: 0.8 ms]
  Range (min … max):    13.6 ms …  25.8 ms    214 runs

Benchmark 3: ./build/day01-no-split
  Time (mean ± σ):      14.3 ms ±   2.3 ms    [User: 13.5 ms, System: 0.7 ms]
  Range (min … max):    12.6 ms …  26.5 ms    218 runs

Benchmark 4: ./build/day01-array-over-map
  Time (mean ± σ):       8.8 ms ±   0.9 ms    [User: 8.0 ms, System: 0.7 ms]
  Range (min … max):     8.0 ms …  15.2 ms    290 runs

Benchmark 5: ./build/day01-better-letters-check
  Time (mean ± σ):       5.1 ms ±   0.6 ms    [User: 4.5 ms, System: 0.5 ms]
  Range (min … max):     4.8 ms …   9.2 ms    606 runs

Benchmark 6: ./build/day01-remove-digits-list
  Time (mean ± σ):       4.9 ms ±   0.9 ms    [User: 4.3 ms, System: 0.5 ms]
  Range (min … max):     4.5 ms …   9.2 ms    613 runs

Summary
  ./build/day01-remove-digits-list ran
    1.03 ± 0.22 times faster than ./build/day01-better-letters-check
    1.79 ± 0.36 times faster than ./build/day01-array-over-map
    2.90 ± 0.69 times faster than ./build/day01-no-split
    3.14 ± 0.75 times faster than ./build/day01-no-string-conversion
    3.27 ± 0.68 times faster than ./build/day01-naive
```
