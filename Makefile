NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = includes
SRC = src/main.c src/token.c src/token_utils.c src/utils.c src/clear.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline -g -fsanitize=address

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
