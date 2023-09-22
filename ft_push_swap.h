/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:50:25 by gabpicci          #+#    #+#             */
/*   Updated: 2023/08/29 22:01:28 by gabpicci         ###   ########.fr       */
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

//List commands
t_node	*lst_mkr(int i, char **av, t_node **list1);
t_node	*ft_lstnew(int n);
t_node	*dupe_list(t_node *stack);

//Checker function
int		checker_errors(char **av);
int		ft_is_order(t_node *stack_a);

//Implementation of the moves
void	ft_swap(t_node **stack, char id);
void	ft_push(t_node **stack, t_node **stack_2, char id);
void	ft_rotate(t_node **stack, char id);
void	ft_reverse(t_node **stack, char id);

//auxiliary moves
void	ft_double_move(t_node **stack_a, t_node **stack_b, int size, int op);
void	ft_swap_rotate(t_node **stack, char id, char op);
void	ft_push_twice(t_node **stack_a, t_node **stack_b, int op);
void	ft_direction_rotate(t_node **stack, int id, int element, int size);

//Utilities
void	ft_write_operations(char op, char id);
void	print_stack(t_node *stack);
t_node	*list_last(t_node *stack);
long	mini_atoi(char *str);
int		ft_lstsz(t_node *lst);

t_node	*lst_clear(t_node **stack_a, char **inputs, int ac);

char	**ft_split(char const *s);
int		count_inputs(char **inputs);

//List math, operations to find a certain positon on the list

int		smallest_element(t_node **original);
int		big_elmnt(t_node **original);
int		mid_point(t_node *stack, int nbr);
void	closest_big(t_node **original, int value);
void	closest_big_to_a(t_node **original, int value);
int		nbr_rank(t_node **stack, int nth);
int		ft_sqrt(unsigned int n);

//Sort functions
void	ft_sort(t_node **stack_a, t_node **stack_b, int size);
void	ft_top3(t_node **stack_a);
void	ft_top5(t_node **stack_a, t_node **stack_b, int size);

void	ft_top5_b(t_node **stack_a, t_node **stack_b);