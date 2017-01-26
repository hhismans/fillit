# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfloure <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 21:22:23 by gfloure           #+#    #+#              #
#*   Updated: 2017/01/26 05:39:58 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC +=	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC +=	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c
SRC +=	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
SRC +=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c
SRC +=	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRC +=	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC +=	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC +=	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC +=	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC +=	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC +=	ft_strnstr.c ft_strrchr.c ft_toupper.c ft_strsplit.c
SRC +=	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
SRC += ft_strnjoin.c ft_strnjoinfree.c

INCLUDES = ./includes
OBJ = $(SRC:.c=.o)
DEL = rm -f
FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)

NOCOL = "\033[00m"
GREEN = "\033[35m"
GOOD = "\033[32m"
ERROR = "\033[31m"
WARN = "\033[33m"
YELLOW = "\033[33m"
RED = "\033[31m"

SUCCES 	= $(GOOD)SUCCESS$(NOCOL)
OK 		= $(GREEN)OK$(NOCOL)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(RED)"Compiling" [ $(NAME) ] $(SUCCES)

%.o: %.c $(INCLUDES)/libft.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)
	@echo $(YELLOW)"Linking" [ $< ] $(OK)

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)

re: fclean all
