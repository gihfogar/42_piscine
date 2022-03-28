/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:22:26 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/25 10:17:15 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	index;

	while (size >= 0)
	{
		index = 0;
		while (index < size - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				swap = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = swap;
			}
			index++;
		}
		size--;
	}
}
