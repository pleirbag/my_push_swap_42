/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:50:32 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/12 21:52:17 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// Swaps the first and second elements of the linked list
void	ft_swap(t_node **stack, char id)
{
	t_node	*temp;

	if (!stack)
		return ;
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

	if (!stack)
		return ;
	if (!stack_2)
		return ;
	temp = (*stack_2);
	(*stack_2) = *stack;
	(*stack) = (*stack)->next;
	(*stack_2)->next = temp; 
	ft_write_operations('p', id);
}

// Rotates linkes list with first element becoming last
void	ft_rotate(t_node **stack, char id)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack)
		return ;
	temp = *stack;
	temp2 = list_iter(*stack);
	temp2->next = temp;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_write_operations('r', id);
}

// Reverse rotates the linked list with last element becoming first
void	ft_reverse(t_node **stack, char id)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack)
		return ;
	temp2 = *stack;
	temp = list_iter(*stack);
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp->next = (*stack);
	(*stack) = temp;
	temp2->next = NULL;
	ft_write_operations('R', id);
}
