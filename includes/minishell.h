/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:55:54 by luebina           #+#    #+#             */
/*   Updated: 2024/10/11 18:06:22 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
//	int				append;
	struct s_token	*next;
}	t_token;

void	tokenize(char *line, t_token **tokens);
void	add_token(t_token **tokens, char *value, t_token_type type);
char	*ft_strjoin_char(char *s1, char c);
char	*ft_strjoin_shell(char *s1, char *s2);
char	*ft_strndup(const char *s, size_t size);
void	clear_tokens(t_token **tokens);
void	command(t_token *tokens);
int		is_builtin(char *cmd);
/* int		execute_builtin(char **cmd); */
size_t	safe_strlcat(char *dest, const char *src, size_t n);

#endif
