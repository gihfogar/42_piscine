/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:01:00 by amarques          #+#    #+#             */
/*   Updated: 2022/01/17 13:26:27 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	line;
	int	col;

	line = 0;
	while (++line <= y && (x > 0 && y > 0)) /* iterar pelo numero de linhas (incrementar o val de 'line' e comparar com o input de 'y';											   check input (if its positive) */
	{
		col = 0;
		while (++col <= x) // iterar pelo numero de colunas (incrementar o valor de 'col' e comparar com o input de 'x')
		{
			if ((col == 1 || col == x) && (line == 1 || line == y)) // verificar se e um canto
			{ 
			   /* todos estes ifs estao ordenados de maneira a evitar que quando y = 1 haja erro nos caracteres dos cantos.
				* ex: \ em vez de / no canto superior esquerdo (no caso da condicao do primeiro else if aparecer antes da condicao do if) */
				if (col == 1 && line == 1) // verificar se e canto superior esquerdo 
					ft_putchar('/');
				else if ((col == 1 && line == y) || (col == x && line == 1)) // verificar se e canto inferior esquerdo ou canto superior direito
					ft_putchar('\\');
				else if (col == x && line == y) // verificar se e o canto inferior direito
					ft_putchar('/');
			}
			else if (col == 1 || col == x || line == 1 || line == y) // como ja verificamos que nao e um canto, sabe-se que estamos no perimetro da figura.
				ft_putchar('*');
			else
				ft_putchar(' '); // como ja sabemos que NAO e um canto e NEM um perimetro, sabemos que e um caracter do meio.
		}
		ft_putchar ('\n'); // no final, print de uma newline
	}
}
