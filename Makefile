# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 15:55:28 by bpuschel          #+#    #+#              #
#    Updated: 2017/09/03 10:37:05 by bpuschel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = checker
NAMEP = push_swap
INCLUDE = includes/
SRC = srcs/
STACK_FILES = stack.c rrotate.c
STACK_OBJ = $(STACK_FILES:.c=.o)
CHECKER_FILES = parse_cmd.c validate.c checker.c
CHECKER_OBJ = $(CHECKER_FILES:.c=.o)
PUSH_FILES = validate.c parse_cmd.c print_cmd.c push_swap.c sort.c \
get_median.c alt_sort.c
PUSH_OBJ = $(PUSH_FILES:.c=.o)
GCC = gcc -Wall -Werror -Wextra -I $(INCLUDE) -Llibft/ -lftprintf -g -o
.PHONY: all clean fclean re

all: libftprintf-all $(NAMEC) $(NAMEP)

clean: libftprintf-clean
	rm -rf $(STACK_OBJ) $(CHECKER_OBJ) $(PUSH_OBJ)

fclean: libftprintf-fclean clean
	rm -rf $(NAMEC)
	rm -rf $(NAMEP)

re: fclean all

$(NAMEC):
	$(GCC) $(NAMEC) $(addprefix $(SRC), $(STACK_FILES) $(CHECKER_FILES))

$(NAMEP):
	$(GCC) $(NAMEP) $(addprefix $(SRC), $(STACK_FILES) $(PUSH_FILES))

libftprintf-all:
	cd libft && $(MAKE)

libftprintf-clean:
	cd libft && $(MAKE) clean

libftprintf-fclean:
	cd libft && $(MAKE) fclean

libftprintf-re:
	cd libft && $(MAKE) re

