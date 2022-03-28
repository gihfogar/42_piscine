/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:01:25 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/21 11:53:32 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

int		main(void)
{
	int a, b, div, mod, *ptr1, *ptr2;

	a = 5;
	b = 2;
	ptr1 = &div;
	ptr2 = &mod;
	ft_div_mod(a, b, ptr1, ptr2);
	printf("Result (11)= %d\n", div);
	printf("Rest (27)= %d\n", mod); 
}

