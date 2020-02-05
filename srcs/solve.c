/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 11:21:05 by jsance            #+#    #+#             */
/*   Updated: 2019/07/14 12:50:51 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** return (1) - find empty
*/

int		find_unassigned(int **board, int *row, int *col)
{
	while (*row < 9)
	{
		*col = 0;
		while (*col < 9)
		{
			if (board[*row][*col] == 0)
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}


/*
** return (1) - found  solution
*/

int		solve(int **board)
{
	int		row;
	int		col;
	int		num;

	row = 0;
	col = 0;
	if (!find_unassigned(board, &row, &col))
		return (1);
	num = 1;
	while (num <= 9)
	{
		if (can_put(board, row, col, num))
		{
			board[row][col] = num;
			if (solve(board))
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}
