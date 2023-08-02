/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:50:32 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/02 16:58:49 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Swaps the first and second elements of the linked list
void	ft_swap(t_node **stack, char id)
{
	t_node	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (!*stack || !(*stack)->next)
		return ;
	ft_write_operations('s', id);
}

// Takes the first element of stack, and moves it to stack 2
void	ft_push(t_node **stack, t_node **stack_2, char id)
{
	t_node	*temp;

	temp = (*stack_2);
	(*stack_2) = *stack;
	(*stack) = (*stack)->next;
	(*stack_2)->next = temp; 
	ft_write_operations('p', id);
}

// Rotates linkes list with last element becoming first
void	ft_rotate(t_node **stack, char id)
{
	t_node	*temp;
	t_node	*temp2;

	temp2 = *stack;
	temp = list_iter(*stack);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp->next = (*stack);
	(*stack) = temp;
	temp2->next = NULL;
	ft_write_operations('r', id);
}

// Reverse rotates the linked list with first element becoming last
void	ft_reverse(t_node **stack, char id)
{
	t_node	*temp;
	t_node	*temp2;

	temp = *stack;
	temp2 = list_iter(*stack);
	temp2->next = temp;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_write_operations('R', id);
}

//two operations at the same time, rrr, rr, ss
void	ft_double_move(t_node *stack_a, t_node *stack_b, int size, int op)
{
	if (op == 's' || size)
	{
		ft_swap(&stack_a, 0);
		ft_swap(&stack_b, 0);
		ft_write_operations('s', 's');
	}
	if (op == 'R')
	{
		ft_reverse(&stack_a, 0);
		ft_reverse(&stack_b, 0);
		ft_write_operations('R', 'r');
	}
	if (op == 'r')
	{
		ft_rotate(&stack_a, 0);
		ft_rotate(&stack_b, 0);
		ft_write_operations('r', 'r');
	}
}
