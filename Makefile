# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 15:55:28 by bpuschel          #+#    #+#              #
#    Updated: 2017/07/26 20:15:28 by bpuschel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = checker
NAMEP = push_swap
INCLUDE = includes/
SRC = srcs/
STACK_FILES = stack.c rrotate.c
STACK_OBJ = $(STACK_FILES:.c=.o)
CHECKER_FILES = parse_cmd.c checker.c
CHECKER_OBJ = $(CHECKER_FILES:.c=.o)
GCC = gcc -Wall -Werror -Wextra -I $(INCLUDE) -Llibft/ -lftprintf -g -o
.PHONY: all clean fclean re

all: libftprintf-all $(NAMEC)

clean: libftprintf-clean
	rm -rf $(STACK_OBJ) $(CHECKER_OBJ)

fclean: libftprintf-fclean clean
	rm -rf $(NAMEC)

re: fclean all

$(NAMEC):
	$(GCC) $(NAMEC) $(addprefix $(SRC), $(STACK_FILES) $(CHECKER_FILES))

libftprintf-all:
	cd libft && $(MAKE)

libftprintf-clean:
	cd libft && $(MAKE) clean

libftprintf-fclean:
	cd libft && $(MAKE) fclean

libftprintf-re:
	cd libft && $(MAKE) re

