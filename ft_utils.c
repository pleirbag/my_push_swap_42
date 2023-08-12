/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:51 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/11 16:40:13 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// writes the output operation to be realized
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

// Similar to atoi returns an long from a string
long	mini_atoi(char *str)
{
	long	i;
	long	pos;
	long	nbr;

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

// debugging function used to print current state of a stack
void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

// Runs thru the list returning last node
t_node	*list_iter(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// returns teh size of the list
int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
