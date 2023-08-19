/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:31 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/19 21:24:20 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// node_name.next = &next_node_name
// node_name.value = value
// new->next = NULL;
// new->value = n;

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	i = 0;
	if (ac > 1)
	{
		if (checker_errors(av))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		stack_a = lst_mkr(ac, av, &stack_a);
		stack_b = NULL;
		ft_sort(&stack_a, &stack_b, ac - 1);
		// print_stack(stack_a);
		// printf("\n");
		// print_stack(stack_b);
		lst_clear(&stack_a);
	}
}
