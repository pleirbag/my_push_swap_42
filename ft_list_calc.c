/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:56:01 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/19 23:12:03 by gabpicci         ###   ########.fr       */
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

void	closest_big(t_node **original, int value)
{
	int		r;
	int		rr;
	t_node	*stack;

	r = 0;
	rr = 0;
	stack = dupe_list(*original);
	while (stack->next && stack->value > value)
	{
		r++;
		stack = stack->next;
	}
	lst_clear(&stack);
	stack = dupe_list(*original);
	while (stack->value > value)
	{
		ft_reverse(&stack, 0);
		rr++;
	}
	lst_clear(&stack);
	if (rr < r)
	{
		while (rr--)
			ft_reverse(original, 'a');
		return ;
	}
	while (r--)
		ft_rotate(original, 'a');
}

void	closest_big_to_a(t_node **original, int value)
{
	int		r;
	int		rr;
	t_node	*stack;

	r = 0;
	rr = 0;
	stack = dupe_list(*original);
	while (stack->next && stack->value < value)
	{
		r++;
		stack = stack->next;
	}
	lst_clear(&stack);
	stack = dupe_list(*original);
	while (stack->value < value)
	{
		ft_reverse(&stack, 0);
		rr++;
	}
	lst_clear(&stack);
	if (rr < r)
	{
		while (rr--)
			ft_reverse(original, 'b');
		return ;
	}
	while (r--)
		ft_rotate(original, 'b');
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

//kind of square root minus a few