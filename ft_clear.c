/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:09:09 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/02 17:33:54 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// clears all the memory allocated for the linked list
t_node	*lst_clear(t_node **stack)
{
	t_node	*temp;

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
	return (*stack);
}
