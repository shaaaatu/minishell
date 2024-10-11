NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = includes
SRC = src/main.c src/token/token.c src/token/token_utils.c src/utils/utils.c src/token/clear.c src/command/command.c src/command/builtin.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
