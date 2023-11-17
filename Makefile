# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:57:40 by yachebla          #+#    #+#              #
#    Updated: 2023/11/17 19:41:07 by yachebla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

FILES = push_swap.c parsing.c push_swap_utilise.c 

 OBJ = $(FILES:.c=.o)
 
 all: $(NAME)
 
 $(NAME): $(OBJ) $(HEADER)
		 $(CC) $(CFLAGS) $(FILES) -o $(NAME)
	
clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re : fclean all