/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:29:53 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/28 14:33:50 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_puzzle_test(int table[10], int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
		if (y == table[i]
			|| i + table[i] == x + y
			|| i - table[i] == x - y)
			return (0);
	return (1);
}

void	ft_puzzle_recursive(int table[10], int *res, int pos)
{
	int	a;
	int	b;

	if (pos == 10)
	{
		*res += 1;
		b = -1;
		while (++b < 10)
			ft_putchar(table[b] + '0');
		ft_putchar('\n');
	}
	else
	{
		a = -1;
		while (++a < 10)
		{
			if (ft_puzzle_test(table, pos, a))
				table[pos] = a;
			ft_puzzle_recursive(table, res, pos + 1);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;
	int	result;

	i = -1;
	while (++i < 10)
		table[i] = -1;
	result = 0;
	ft_puzzle_recursive(table, &result, 0);
	return (result);
}
/*
int		main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
}
*/
