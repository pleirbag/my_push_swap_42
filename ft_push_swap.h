/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:50:25 by gabpicci          #+#    #+#             */
/*   Updated: 2023/07/28 20:24:46 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	int			value;
	struct list	*next;
}	t_node;

t_node	*lst_mkr(int i, char **av, t_node **list1);
t_node	*ft_lstnew(int n);
int	mini_atoi(char *str);

int	checker_errors(char **av);