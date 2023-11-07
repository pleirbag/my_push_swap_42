/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:36:35 by gabpicci          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:54 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	direction(int r, int rr, int stack, t_node **original)
{
	if (rr < r)
	{
		while (rr--)
			ft_reverse(original, stack);
		return ;
	}
	while (r--)
		ft_rotate(original, stack);
}

void	closest_big(t_node **original, int value)
{
	int		r;
	int		rr;
	t_node	*stack;

	r = 0;
	rr = 0;
	stack = dupe_list(*original);
	while (stack->value > value)
	{
		r++;
		ft_rotate(&stack, 0);
	}
	lst_clear(&stack, 0, 0);
	stack = dupe_list(*original);
	while (stack->value > value)
	{
		ft_reverse(&stack, 0);
		rr++;
	}
	lst_clear(&stack, 0, 0);
	direction(r, rr, 'a', original);
}

void	closest_big_to_a(t_node **original, int value)
{
	int		r;
	int		rr;
	t_node	*stack;

	r = 0;
	rr = 0;
	stack = dupe_list(*original);
	while (stack->value < value)
	{
		r++;
		ft_rotate(&stack, 0);
	}
	lst_clear(&stack, 0, 0);
	stack = dupe_list(*original);
	while (stack->value < value)
	{
		ft_reverse(&stack, 0);
		rr++;
	}
	lst_clear(&stack, 0, 0);
	direction(r, rr, 'b', original);
}
