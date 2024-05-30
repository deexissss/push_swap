# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:33:47 by tjehaes           #+#    #+#              #
#    Updated: 2024/05/21 15:02:10 by tjehaes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = pushswap

PRINTFLIB = printf/libftprintf.a
LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra 

BLUE := \033[0;34m
PINK := \033[1;35m
BLUE2 := \033[0;36m
NOCOLOR := \033[0m

SRC = push_swap.c operations.c operations2.c stack_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib_compilation push_swap

lib_compilation :
	@echo "$(BLUE)STARTING COMPILATION$(NOCOLOR)"
	@cd printf && make
	@cd libft && make

push_swap: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(PRINTFLIB) -o pushswap
	@echo "$(BLUE)COMPILATION READY$(NOCOLOR)"

clean:
	@echo "$(BLUE2)STARTING CLEANING$(NOCOLOR)"
	@rm -f $(OBJ)
	@cd printf && make clean
	@cd libft && make clean
	@echo "$(BLUE2)CLEANING DONE$(NOCOLOR)"

fclean: clean
	@echo "$(BLUE2)STARTING CLEANING$(NOCOLOR)"
	@rm -f $(OBJ)
	@cd printf && make fclean
	@cd libft && make fclean
	@echo "$(BLUE2)EVERYTHING IS CLEANUP$(NOCOLOR)"

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@
re: fclean all

.PHONY: all pushswap clean fclean re printf libft
