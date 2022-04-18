/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:10:38 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/31 15:18:23 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	lim;
	int	i;
	int	*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	lim = max - min - 1;
	if ((buffer = malloc(lim * sizeof(int))) == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	i = 0;
	while (i <= lim)
	{
		buffer[i] = min + i;
		i++;
	}
	return (lim + 1);
}

void	debug_dump_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]");
}

int		main(void)
{
	int	min;
	int	max;
	int	*range;
	int	bound;

	min = 2;
	max = 10;
	bound = ft_ultimate_range(&range, min, max);
	printf("min = %d, max = %d -> (limite = %d) ", min, max, bound);
	fflush(stdout);
	debug_dump_array(range, bound + 2);
}
