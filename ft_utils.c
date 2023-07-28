/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:51 by gabpicci          #+#    #+#             */
/*   Updated: 2023/07/28 20:14:05 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_write_operations(char op, char id)
{
	if (id)
	{
		if (op == 'r' || op == 's' || op == 'p')
		{
			write(1, &op, 1);
			write(1, &id, 1);
			write(1, "\n", 1);
		}
		else if (op == 'R')
		{
			write(1, "rr", 2);
			write(1, &id, 1);
			write(1, "\n", 1);
		}
	}
}

int	mini_atoi(char *str)
{
	int	i;
	int	pos;
	int	nbr;

	i = 0;
	pos = 1;
	nbr = 0;
	if ((str[i] == '-' || str[i] == '+' ))
	{
		if (str[i] == '-')
			pos = -pos;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (pos * nbr);
}