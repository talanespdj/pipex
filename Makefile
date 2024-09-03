NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -g3

SRC = exec.c \
	split.c \
	utils.c \
	pipex.c \
	process.c \

OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	echo "\033[1mpipex ready\033[0m"

clean:
	rm -rf $(OBJS)
	echo "c'est clean"

fclean: clean
	rm -rf $(NAME)
	echo "c'est fclean"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
