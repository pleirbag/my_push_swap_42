/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:31 by gabpicci          #+#    #+#             */
/*   Updated: 2023/07/28 20:25:33 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// node_name.next = &next_node_name
// node_name.value = value
// new->next = NULL;
// new->value = n;

#include "ft_push_swap.h"

int main(int ac, char **av)
{
	t_node *list1;
	int i = 0;

	list1 = lst_mkr(ac, av, &list1);
	if (checker_errors(av))
		return (-1);
	while (av[i + 1])
	{
		printf("lst in px %d\n", list1->value);
		list1 = list1->next;
		i++;
	}
	// printf("lst in px %d\n", list1->value);
}
