# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasinsensoy <yasinsensoy@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 18:04:43 by ysensoy           #+#    #+#              #
#    Updated: 2022/09/11 18:26:43 by yasinsensoy      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = $(wildcard *.c)
OBJ = $(SRC:.c = .o)

all: $(NAME)

$(NAME):
	$(CC) $(CLAFGS) $(SRC) $(OBJ)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
