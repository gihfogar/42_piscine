/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:39:03 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/27 16:51:47 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char p)
{
	write(1, &p, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	verify_error(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] < 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (i + 1 < ft_strlen(str) && str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = ft_strlen(base);
	if (verify_error(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
		}
		if (nbr < len)
		{
			ft_putchar(base[nbr]);
		}
		if (nbr >= len)
		{
			ft_putnbr_base(nbr / len, base);
			ft_putnbr_base(nbr % len, base);
		}
	}
}
/*
int main()
{
	char *base_dec = "0123456789";
   	char *base_bin = "01";
	char *base_hexa = "0123456789abcdef";
	char *base_oct = "poneyvif";

	ft_putnbr_base(0, base_dec);
	ft_putchar('\n');
	ft_putnbr_base(2147483647, base_bin);
	ft_putchar('\n');
	ft_putnbr_base(479, base_hexa);
	ft_putchar('\n');
	ft_putnbr_base(479, base_oct);
	ft_putchar ('\n');
}
*/
