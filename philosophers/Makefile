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
