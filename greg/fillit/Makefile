# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfloure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 18:14:19 by gfloure           #+#    #+#              #
#*   Updated: 2017/01/19 23:37:37 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DEFRULE = all

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes\
		 libft

SRC = ft_error.c ft_check_len.c ft_read.c
SRC += main.c ft_nb_block.c ft_check_sharp.c
SRC += ft_fill_tab.c ft_check_char.c
SRC += ft_check_chariot.c ft_create_tab.c
SRC += ft_check_tetri.c

OBJ = $(SRC:.c=.o)

LIBFT = -Llibft/ -lft

LIBP = $(addprefix -L, $(LIBNAME)/)
OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP = $(foreach dir, $(INCDIR), -I$(dir))

CLEAR = "\033[2k"
BLACK = "\033[1;30m"
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
VIOLET = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NOCOL = "\033[0m"

SUCCES = $(GREEN)SUCCES$(NOCOL)
OK     = $(VIOLET)OK$(NOCOL)


all: libftcomp $(OBJDIR) $(NAME)


libftcomp:
	@make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@$(CC) $(FLAGS) -o $@ $^ $(INCP) $(LIBFT)
	@echo "Compiling" [ $(NAME) ] $(SUCCES)

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all
