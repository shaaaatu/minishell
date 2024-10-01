NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)
LIBFT = ../libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	make -C ../libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ../libft

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	make fclean -C ../libft

re: fclean all
