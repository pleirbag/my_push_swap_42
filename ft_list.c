/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:22:43 by gabpicci          #+#    #+#             */
/*   Updated: 2023/07/28 20:12:23 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

t_node	*lst_mkr(int i, char **av, t_node **list1)
{
	t_node	*head;
	t_node 	*tmp;

	head = *list1;
	if (*list1 == NULL)
		*list1 = ft_lstnew(mini_atoi(av[1]));
	while (--i > 0)
	{
		tmp = ft_lstnew(mini_atoi(av[i]));
		tmp->next = head;
		head = tmp;
	}
	// while (av[i + 1])
	// {
	// 	printf("lst in px %d = %d\n", i, head->value);
	// 	head = head->next;
	// 	i++;
	// }
	return (head);
}
