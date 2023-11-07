/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:56:01 by gabpicci          #+#    #+#             */
/*   Updated: 2023/10/23 19:43:12 by gabpicci         ###   ########.fr       */
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
int	big_elmnt(t_node **original)
{
	int		max;
	t_node	*stack;

	stack = *original;
	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	smallest_ignore(t_node **original, int ignore)
{
	int		min;
	t_node	*stack;

	stack = *original;
	min = big_elmnt(&stack);
	while (stack)
	{
		if (min > stack->value && stack->value > ignore)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

//Finds the nth smallest number in a list, and returns its value
int	nbr_rank(t_node **stack, int nth)
{
	int	cv;

	cv = smallest_element(stack);
	if (!nth)
		return (0);
	while (--nth)
		cv = smallest_ignore(stack, cv);
	return (cv);
}

//solves for the square root of a number -1
//in order to determine the size of the blocks used for the sorting algorithm
int	ft_sqrt(unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n < 2)
		return (n);
	while ((i * i) < n)
	{
		i++;
		if (i >= 46341)
			return (-1);
	}
	return (i - 2);
}
