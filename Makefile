#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 17:30:41 by dmaslenn          #+#    #+#              #
#    Updated: 2017/10/24 18:52:31 by dmaslenn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

SRC =	minishell.c \
		lsout.c \
		lsoutthesecond.c \
		addk.c \
		helper.c \
		environment.c \
		findcom.c \
		sortinput.c \
		starter.c \
		separate.c \
		unssetenv.c \
		checkifecho.c \
		freespaces.c \
		echoquots.c \
		validator.c \
		countl.c \
		findenv.c \
		dolecho.c \
		add.c 

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Werror -Wextra

INC = ./

LIB =  -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@$(CC) $(FLG) -I $(INC) -c $<

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)

re: fclean all