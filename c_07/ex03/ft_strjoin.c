/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussaca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:19:24 by gbussaca          #+#    #+#             */
/*   Updated: 2022/01/31 15:45:14 by gbussaca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_compute_final_length(char **strings, int size, int sep_length)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_strlen(strings[index]);
		final_length += sep_length;
		index++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		full_length;
	int		index;
	char	*read_head;
	char	*string;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	full_length = ft_compute_final_length(strs, size, ft_strlen(sep));
	if (!(string = (char *)malloc((full_length + 1) * sizeof(char))))
		return (0);
	read_head = string;
	index = 0;
	while (index < size)
	{
		ft_strcpy(read_head, strs[index]);
		read_head += ft_strlen(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(read_head, sep);
			read_head += ft_strlen(sep);
		}
		index++;
	}
	*read_head = '\0';
	return (string);
}

int		main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc(4 * sizeof(strs));
	strs[0] = "Nada";
	strs[1] = "0123456789";
	strs[2] = "Geovana";
	strs[3] = "9876543210";
	separator = "";
	index = 0;
	while (index < 4)
	{
		result = ft_strjoin(index, strs, separator);
		printf("result with size = %d : $%s$\n", index, result);
		free(result);
		index++;
	}
}
