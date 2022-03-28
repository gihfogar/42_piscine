/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:20:15 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/21 12:13:08 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab[i] = tab [size -1 - i];
		tab[size - 1 - i] = swap;
		i++;
	}
}

void	ft_rev_int_tab(int *tab, int size);

int		main(void)
{
	int tab[20];
	int i;
	int size;

	size = 20;
	i = 0;
	while (i < size)
	{
		tab[i] = size - i;
		i++;
	}
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d: %d\n", i + 1, tab[i]);
		i++;
	}
}
