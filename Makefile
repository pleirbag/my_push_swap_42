# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 14:53:33 by gabpicci          #+#    #+#              #
#    Updated: 2023/10/24 15:42:13 by gabpicci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

RM = rm -f

SRC = ft_checks.c ft_list.c ft_operations.c ft_push_swap.c ft_utils.c \
		  ft_sort.c ft_extra_utils.c ft_list_calc.c ft_inputs.c ft_close.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	@echo "remove push_swap... done!"
	$(RM) $(NAME)
	
re: fclean all
