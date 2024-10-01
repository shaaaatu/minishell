/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:26:53 by luebina           #+#    #+#             */
/*   Updated: 2024/10/01 22:58:31 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_var_value(char *line)
{
	int		i;
	char	*var_name;
	char	*env_value;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	var_name = ft_strndup(line, i);
	env_value = getenv(var_name);
	free(var_name);
	if (env_value)
		return (env_value);
	return (NULL);
}

int	env_token(char **value, char *line)
{
	char	*env_value;
	int		i;

	i = 0;
	env_value = NULL;
	env_value = env_var_value(line);
	if (env_value)
		*value = ft_strjoin_shell(*value, env_value);
	while (ft_isalnum(line[i]) || line[i] == '_')
	{
		if (!env_value)
		{
			*value = ft_strjoin_char(*value, line[i]);
		}
		i++;
	}
	return (i + 1);
}

int	quote_token(char *line, t_token **tokens)
{
	char	quote;
	char	*value;
	int		i;

	quote = *line;
	i = 1;
	value = NULL;
	while (line[i] && line[i] != quote)
	{
		if (quote == '"' && line[i] == '$')
			i += env_token(&value, line + i + 1);
		else
		{
			value = ft_strjoin_char(value, line[i]);
			i++;
		}
	}
	if (line[i - 1] != quote)
	{
		printf("Error\n");
		free(value);
		return (i);
	}
	printf("%s\n", value);
	add_token(tokens, value, WORD);
	free(value);
	return (i);
}

int	word_token(char *line, t_token **tokens)
{
	int		i;
	int		l;
	char	*word;

	i = 0;
	l = -1;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
		&& line[i] != '|' && line[i] != '<' && line[i] != '>')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	while (++l < i)
		word[l] = line[l];
	word[l] = '\0';
	add_token(tokens, word, WORD);
	free(word);
	return (i - 1);
}

void	tokenize(char *line, t_token **tokens)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
			;
		else if (line[i] == '|')
			add_token(tokens, "|", PIPE);
		else if (line[i] == '<' && line[i + 1] == '<' && line[i++])
			add_token(tokens, "<<", HEREDOC);
		else if (line[i] == '>' && line[i + 1] == '>' && line[i++])
			add_token(tokens, ">>", REDIR_IN);
		else if (line[i] == '<')
			add_token(tokens, "<", REDIR_IN);
		else if (line[i] == '>')
			add_token(tokens, ">", REDIR_OUT);
		else if (line[i] == '\'' || line[i] == '"')
			i += quote_token(line + i, tokens);
		else if (line[i] == '$')
			i += ft_strlen(env_var_value(line + i));
		else
			i += word_token(line + i, tokens);
	}
}
