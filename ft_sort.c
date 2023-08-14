/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:51:03 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/14 23:03:45 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_top3(t_node **stack_a)
{
	int	nbr1;
	int	nbr2;
	int	nbr3;

	nbr1 = (*stack_a)->value;
	nbr2 = (*stack_a)->next->value;
	nbr3 = (*stack_a)->next->next->value;
	if (nbr1 > nbr2)
	{
		if (nbr2 > nbr3)
			ft_swap_rotate(stack_a, 'a', 'R');
		else if (nbr2 < nbr3 && nbr3 > nbr1)
			ft_swap(stack_a, 'a');
		else if (nbr2 < nbr3)
			ft_rotate(stack_a, 'a');
	}
	if (nbr1 < nbr2)
	{
		if (nbr2 > nbr3 && nbr3 < nbr1)
			ft_reverse(stack_a, 'a');
		else if (nbr2 > nbr3)
			ft_swap_rotate(stack_a, 'a', 'r');
	}
}

// void	ft_top5(t_node **stack_a, t_node **stack_b, int size)
// {
// 	if (size == 4)
// 	{
// 		ft_push(stack_a, stack_b, 'b');
// 		ft_top3(stack_a);
// 		while ((*stack_a)->value < (*stack_b)->value)
// 			ft_direction_rotate(stack_a, 'a', 'm', size);
// 		ft_push(stack_b, stack_a, 'a');
// 		while (ft_is_order(*stack_a))
// 			ft_direction_rotate(stack_a, 'a', 'm', size);
// 	}
// 	if (size == 5)
// 	{
// 		ft_push_twice(stack_a, stack_b, 'b');
// 		ft_top3(stack_a);
// 		while (stack_b)
// 		{
// 			while ((*stack_a)->value < (*stack_b)->value)
// 				ft_direction_rotate(stack_a, 'a', 'm', size);
// 			ft_push(stack_b, stack_a, 'a');
// 			while (ft_is_order(*stack_a))
// 				ft_direction_rotate(stack_a, 'a', 'm', size);
// 		}
// 	}
// }

void	ft_top5(t_node **stack_a, t_node **stack_b, int size)
{
	int cs;
	int i;

	cs = size + 1;
	while (--cs > 3)
	{
		i = smallest_element(stack_a);
		while ((*stack_a)->value > i)
			ft_direction_rotate(stack_a, 'a', 'm', size);
		ft_push(stack_a, stack_b, 'b');
	}
	ft_top3(stack_a);
	while (*stack_b)
			ft_push(stack_b, stack_a, 'a');
}

// Starts the sorting process
void	ft_sort(t_node **stack_a, t_node **stack_b, int size)
{
	if (!ft_is_order(*stack_a))
		return ;
	else if (size == 2)
		ft_swap(stack_a, 'a');
	else if (size == 3)
		ft_top3(stack_a);
	else if (size == 4 || size == 5)
		ft_top5(stack_a, stack_b, size);
	if (stack_b)
		return ;
}
