# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 18:04:43 by ysensoy           #+#    #+#              #
#    Updated: 2022/09/12 15:25:48 by ysensoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers.a
CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c = .o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CLAFGS) $(OBJ) -o $(NAME)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all
