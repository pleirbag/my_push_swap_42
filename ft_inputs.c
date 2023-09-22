/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:55:38 by gabpicci          #+#    #+#             */
/*   Updated: 2023/09/22 22:18:34 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_wtspc(int arg)
{
	if (arg == ' ' || (arg >= 9 && arg <= 13))
		return (1);
	return (0);
}

int	nbr_str(char const *s)
{
	int	sz;
	int	i;

	sz = 0;
	i = -1;
	while (s[++i])
	{
		if (!is_wtspc(s[i]) && (is_wtspc(s[i + 1]) || s[i + 1] == 0))
			sz++;
	}
	return (sz);
}

char	*str_mkr(char const *s, char *new_str)
{
	int		i;

	i = 0;
	while (!is_wtspc(s[i]) && s[i])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s[++i] && !is_wtspc(s[i]))
		new_str[i] = s[i];
	new_str[i] = 0;
	return (new_str);
}

// int	total_size(char **av)
// {
// 	int	sz;
// 	int	cc;
// 	int	i;

// 	i = -1;
// 	sz = 0;
// 	cc = 0;
// 	while (av[++cc])
// 	{
// 		while (av[cc][++i])
// 		{
// 			if (!is_wtspc(av[cc][i]) && (is_wtspc(av[cc][i]) || av[cc][i] == 0))
// 				sz++;
// 		}
// 	}
// 	return (sz);
// }

char	**ft_split(char const *s)
{
	int		i;
	int		ii;
	char	**matrix;
	// int teste;

	i = 0;
	// teste = -1;
	ii = 0;
	matrix = (char **)malloc((nbr_str(s) + 2) * sizeof(char *));
	matrix[ii++] = 0;
	if (!matrix)
		return (NULL);
	while (s[i])
	{
		if (!is_wtspc(s[i]))
		{
			matrix[ii] = str_mkr(&s[i], matrix[ii]);
			ii++;
			while (s[i] && !is_wtspc(s[i]))
				i++;
		}
		else
			i++;
	}
	matrix[ii] = NULL;
	// while (matrix[++teste])
	// 	printf("%s\n", matrix[teste]);
	return (matrix);
}

int	count_inputs(char **inputs)
{
	int	i;

	i = 1;
	while (inputs[i])
		i++;
	return (i);
}
