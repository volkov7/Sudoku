/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsance <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:11:51 by jsance            #+#    #+#             */
/*   Updated: 2019/07/14 17:24:49 by jsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		check_error(char **argv, int argc)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (argc-- > 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((!(argv[i][j] >= '1' && argv[i][j] <= '9')
					&& argv[i][j] != '.'))
				return (0);
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				count++;
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	if (count < 17)
		return (0);
	return (1);
}

void	fill_board(int **board, char **argv)
{
	int		j;
	int		i;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (**argv == '.')
				board[i][j] = 0;
			else if (**argv >= '1' && **argv <= '9')
				board[i][j] = **argv - '0';
			j++;
			(*argv)++;
		}
		argv++;
		i++;
	}
}

void	print_board(int **board)
{
	int		i;
	int		j;
	char	translator;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			translator = board[i][j] + '0';
			write(1, &translator, 1);
			j++;
			if (j != 9)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		**board;
	int		i;

	if (argc == 10 && check_error(argv, argc))
	{
		argv++;
		board = (int**)malloc(sizeof(board) * 9);
		i = 0;
		while (i < 9)
		{
			board[i] = (int*)malloc(sizeof(board) * 9);
			i++;
		}
		fill_board(board, argv);
		if (solve(board) == 1)
			print_board(board);
		else
			write(1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
