/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:55:54 by luebina           #+#    #+#             */
/*   Updated: 2024/11/13 20:23:43 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef enum e_op_precedence
{
	AND_OR,
	PIPE,
	REDIR,
	WORD
}	t_op_precedence;

typedef struct s_ast
{
	char			*value;
	/* t_cmd_type	type; */
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

char	**tokenize(char *line);
void	add_token(char ***tokens, char *value);
char	*ft_strjoin_char(char *s1, char c);
char	*ft_strjoin_shell(char *s1, char *s2);
char	*ft_strndup(const char *s, size_t size);
void	clear_tokens(char ***tokens);
void	command(t_ast *tokens);
int		is_builtin(char *cmd);
/* int		execute_builtin(char **cmd); */
size_t	safe_strlcat(char **dest, const char *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
t_ast	*parsing(char **tokens);

#endif
