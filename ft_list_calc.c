/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:56:01 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/14 22:59:52 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//finds the smallest int on the linked list
int	smallest_element(t_node **original)
{
	int		min;
	t_node	*stack;

	stack = *original;
	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

//finds the biggest int on the linked list
int	biggest_element(t_node **original)
{
	int		max;
	t_node	*stack;

	stack = *original;
	max = stack->value;
	while (stack->next)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

//returns the position of the desire number on the list
int	mid_point(t_node *stack, int nbr)
{
	int	position;

	position = 1;
	while (stack->value != nbr)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}
