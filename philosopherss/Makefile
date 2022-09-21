# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 18:04:43 by ysensoy           #+#    #+#              #
#    Updated: 2022/09/20 18:45:15 by ysensoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers.a
CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CLAFGS) $(OBJ) -o $(NAME)
	@echo "####################################################"
	@echo "# ********   *      *     *   *            ******* #"
	@echo "# *      *   *      *     *   *            *     * #"
	@echo "# ********   ********     *   *            *     * #"
	@echo "# *          *      *     *   *            *     * #"
	@echo "# *          *      *     *   *********    ******* #"
	@echo "####################################################"

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: clean
	@all

.PHONY: all fclean clean re
