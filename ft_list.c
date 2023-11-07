/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:22:43 by gabpicci          #+#    #+#             */
/*   Updated: 2023/10/23 19:19:47 by gabpicci         ###   ########.fr       */
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

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*i;

	i = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (i->next)
			i = i->next;
		i->next = new;
	}
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

t_node	*dupe_list(t_node *stack)
{
	t_node	*head;

	head = NULL;
	while (stack)
	{
		ft_lstadd_back(&head, ft_lstnew(stack->value));
		stack = stack->next;
	}
	return (head);
}
