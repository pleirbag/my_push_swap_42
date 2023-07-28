/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:46 by gabpicci          #+#    #+#             */
/*   Updated: 2023/07/28 21:38:09 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	ft_strstr(const char *str, const char *find)
// {
// 	int	i;
// 	int	b;

// 	i = 0;
// 	b = 0;
// 	if (*find == 0)
// 		return (-1);
// 	while (str[i])
// 	{
// 		b = 0;
// 		while (str[i + b] == find[b] && str[i + b] && find[b])
// 		{
// 			b++;
// 			if (!find[b] && !str[i + b])
// 				return (0);
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// checks for repeats in the input
int	check_rp(char **av)
{
	int	i;
	int	c;

	i = 1;
	c = 1;
	while (av[i + 1])
	{
		while (av[i + c])
		{
			if (ft_strcmp(av[i], av[i + c]) == 0)
				return (-1);
			c++;
		}
		c = 1;
		i++;
	}
	return (0);
}

//checks for errors on input
int	checker_errors(char **av)
{
	int	i;
	int	b;

	i = 1;
	b = 0;
	while (av[i])
	{
		if (((av[i][b] <= 48 || av[i][b] >= 57) && av[i][b]) || check_rp(av))
		{
			printf("Error\n");
			return (-1);
		}
		if (av[i][b])
			b++;
		if (!av[i][b])
		{
			i++;
			b = 0;
		}
	}
	return (0);
}
