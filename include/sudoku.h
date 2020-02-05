#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

int		solve(int **board);
int		can_put(int **board, int row, int col, int num);

#endif