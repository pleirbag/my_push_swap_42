/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:50:25 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/02 17:13:51 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct list
{
	int			value;
	struct list	*next;
}	t_node;

t_node	*lst_mkr(int i, char **av, t_node **list1);
t_node	*ft_lstnew(int n);

int		checker_errors(char **av);

void	ft_swap(t_node **stack, char id);
void	ft_push(t_node **stack, t_node **stack_2, char id);
void	ft_rotate(t_node **stack, char id);
void	ft_reverse(t_node **stack, char id);

void	ft_write_operations(char op, char id);
void	print_stack(t_node *stack);
t_node	*list_iter(t_node *stack);
long	mini_atoi(char *str);

t_node	*lst_clear(t_node **stack_a);