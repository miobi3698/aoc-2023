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
