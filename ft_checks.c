/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:46 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/19 21:43:49 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// compares strings, returns 0 if identical, and a value != 0 when different
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Checks if the string is a valid number, or + - sign
// int	ft_check_nbr(void)

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
	long	i;
	long	b;

	i = 1;
	b = 0;
	while (av[i])
	{
		if (((av[i][b] < 48 || av[i][b] > 57) && av[i][b]) || check_rp(av))
			return (-1);
		if (av[i][b])
			b++;
		if (!av[i][b])
		{
			i++;
			b = 0;
		}
		if (av[i])
		{
			if (mini_atoi(av[i]) > 2147483647 || mini_atoi(av[i]) < -2147483648)
				return (-1);
		}
	}
	return (0);
}

//checks if the list is in order
int	ft_is_order(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (-1);
	}
	return (0);
}
