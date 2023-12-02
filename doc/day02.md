# Day 02

## Problem

### Problem 1

You have an input consist of lines in the form:
`Game <id>: <count> <color>(, <count> <color>)*(; <count> <color>(, <count> <color>)*)*`

Game have a ';' separated list of subsets of cubes (count + color) ',' separated
Color can only be of 'red', 'green', 'blue'
Check which game does the cube counts per subsets not larger than:
`12 red, 13 green, 14, blue`
Sum the game ids

### Solution 1 - Naive way

Split input into lines
Grab the game_id, subsets of cubes
Check that each of the subset have cube count smaller or equal than requirements
Sum the game ids

### Problem 2

Same input as problem 1 but
- Calculate the minimum number of cubes to satisfy the game
- Multiply the cubes count by color into power
- Sum all the powers


### Solution 2 - Naive way

Split input into lines
Grab the game_id, subsets of cubes
Get the max number of cubes by color
Mutiply each color into power
Sum all the powers

