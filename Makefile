NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = includes
SRC = src/main.c \
	  src/lexer/lexer.c \
	  src/lexer/lexer_utils.c \
	  src/utils/ft_realloc.c \
	  src/utils/ft_strjoin_shell.c \
	  src/utils/ft_strjoin_char.c \
	  src/utils/ft_strndup.c \
	  src/utils/safe_strlcat.c \
	  src/parser/parser.c \
	  # src/token/clear.c \
	  # src/command/command.c \
	  src/command/builtin.c
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
