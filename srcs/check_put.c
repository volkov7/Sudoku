/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:05:23 by jsance            #+#    #+#             */
/*   Updated: 2019/07/14 12:08:24 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_in_box(int **board, int start_row, int start_col, int num)
{
	int		row;
	int		col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (board[row + start_row][col + start_col] == num)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		check_in_col(int **board, int col, int num)
{
	int		row;

	row = 0;
	while (row < 9)
	{
		if (board[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int		check_in_row(int **board, int row, int num)
{
	int		col;

	col = 0;
	while (col < 9)
	{
		if (board[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int		can_put(int **board, int row, int col, int num)
{
	return (check_in_row(board, row, num)
			&& check_in_col(board, col, num)
			&& check_in_box(board, row - row % 3, col - col % 3, num)
			&& board[row][col] == 0);
}
