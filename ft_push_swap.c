/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:31 by gabpicci          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:18 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	char	**inputs;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	if (ac == 2)
		inputs = ft_split(av[1]);
	else
		inputs = av;
	i = count_inputs(inputs);
	if (i == 1)
		return (0);
	if (ac > 1)
	{
		if (checker_errors(inputs))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		stack_a = lst_mkr(i, inputs, &stack_a);
		stack_b = NULL;
		ft_sort(&stack_a, &stack_b, i - 1);
		lst_clear(&stack_a, inputs, ac);
	}
}
