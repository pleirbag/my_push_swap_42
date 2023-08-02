/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:22:43 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/02 17:02:07 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// creates a new node with value n, and then returns said node
t_node	*ft_lstnew(int n)
{
	t_node	*n_node;

	n_node = (t_node *)malloc(sizeof(t_node));
	if (!n_node)
		return (NULL);
	n_node->value = n;
	n_node->next = NULL;
	return (n_node);
}

// creates an linke list with the value of the arguments passed in ARGV in order
t_node	*lst_mkr(int i, char **av, t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	*stack = NULL;
	head = *stack;
	while (--i > 0)
	{
		tmp = ft_lstnew(mini_atoi(av[i]));
		tmp->next = head;
		head = tmp;
	}
	return (head);
}
