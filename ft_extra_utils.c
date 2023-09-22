/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:09:46 by gabpicci          #+#    #+#             */
/*   Updated: 2023/09/22 22:47:55 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_rotate(t_node **stack, char id, char op)
{
	ft_swap(stack, id);
	if (op == 'R')
		ft_reverse(stack, id);
	if (op == 'r')
		ft_rotate(stack, id);
}

//two operations at the same time, rrr, rr, ss
void	ft_double_move(t_node **stack_a, t_node **stack_b, int size, int op)
{
	if (op == 's' || size)
	{
		ft_swap(stack_a, 0);
		ft_swap(stack_b, 0);
		ft_write_operations('s', 's');
	}
	if (op == 'R')
	{
		ft_reverse(stack_a, 0);
		ft_reverse(stack_b, 0);
		ft_write_operations('R', 'r');
	}
	if (op == 'r')
	{
		ft_rotate(stack_a, 0);
		ft_rotate(stack_b, 0);
		ft_write_operations('r', 'r');
	}
}

//pushes two times to the top of the same stack
void	ft_push_twice(t_node **stack_a, t_node **stack_b, int op)
{
	ft_push(stack_a, stack_b, op);
	ft_push(stack_a, stack_b, op);
}

// clears all the memory allocated for the linked list
t_node	*lst_clear(t_node **stack, char **inputs, int ac)
{
	t_node	*temp;
	int		i;
	int		x;

	i = 0;
	x = count_inputs(inputs) + ac;
	if (!(*stack)->next)
	{
		free(*stack);
		return (*stack);
	}
	temp = (*stack)->next;
	while (temp)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	// if (ac == 2 && 0)
	// {
	// 	free(inputs);
	// 	inputs++;
	// 	i++;
	// }
	return (*stack);
}

//Rotates list in the most efficient direction
void	ft_direction_rotate(t_node **stack, int id, int element, int size)
{
	int	i;

	if (element == 'm')
	{
		i = mid_point(*stack, smallest_element(stack));
		if (i <= size / 2)
			ft_rotate(stack, id);
		else if (i > size / 2)
			ft_reverse(stack, id);
	}
	if (element == 'M')
	{
		i = mid_point(*stack, big_elmnt(stack));
		if (i < size / 2)
			ft_rotate(stack, id);
		else
			ft_reverse(stack, id);
	}
}
