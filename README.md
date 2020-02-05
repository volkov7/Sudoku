# Sudoku rules
Given a partially filled 9×9 2D array, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.
# Naive Algorithm:
The Naive Algorithm is to generate all possible configurations of numbers from 1 to 9 to fill the empty cells. Try every configuration one by one until the correct configuration is found.
# Installing and running
Install:
```
make && make clean
```
Run:
```
./sudouku [put youre sudoke like in example.txt]
```
If input will be wrong the programm print Error.
![Example](https://github.com/volkov7/Sudoku/raw/master/example.png)