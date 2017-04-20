# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 20:00:21 by hhismans          #+#    #+#              #
#    Updated: 2017/04/19 17:24:03 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	fillit

SRC =	src/main.c			\
		src/bricks.c			\
		src/map.c			\
		src/parse.c			\

LIB =	-lft -L./libft\
		-I includes/ -I libft/ 
DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAG) -o $@ $(OBJ) $(LIB)
	@echo "\033[1;33mmake -> $@ created\033[1;37m"

%.o: %.c
	@gcc $(FLAG) -o $@ -c $< -I./libft -I ./includes
	@echo "\033[36mCompilation of\033[1m $< \033[32m done \033[37m"
clean:
	@make clean -C libft
	@$(DEL) $(OBJ)
	@echo "\033[0;33mclean -> .o deleted"

fclean: clean
	@make fclean -C libft
	@$(DEL) $(NAME)
	@echo "\033[1;31mfclean -> $(NAME) deleted\033[37m"

re: fclean all
	@make fclean -C libft
	@echo "\033[1;30mre -> $(NAME) reloaded\033[1;37m"

.PHONY: all clean fclean re
