/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:26:53 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 17:54:00 by luebina          ###   ########.fr       */
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

char	*quote_analysis(char *line)
{
	char	quote;
	char	*value;
	int		i;

	quote = *line;
	i = 1;
	value = NULL;
	while (line[i] && line[i] != quote)
	{
		/* if (quote == '"' && line[i] == '$') */
		/* 	i += env_token(&value, line + i + 1); */
		/* else */
		/* { */
		value = ft_strjoin_char(value, line[i]);
		i++;
		/* } */
	}
	if (line[i] != quote)
	{
		free(value);
		return (NULL);
	}
	return (value);
}

int	word_token(char *line, char **tokens)
{
	int		i;
	char	*word;
	bool	quote;

	i = 0;
	word = NULL;
	quote = false;
	while (line[i] && !(!quote && (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
					|| line[i] == '|' || line[i] == '<' || line[i] == '>'))
		  )	{
		if (!quote && (line[i] == '\'' || line[i] == '"'))
		{
			quote = true;
			/* safe_strlcat(&word, quote_analysis(line + i), */
			/* 	ft_strlen(quote_analysis(line + i))); */
			/* while (line[i]) */
			/* { */
			/* 	if (line[i - 1] && line[i - 1] == quote) */
			/* 		break; */
			/* 	word = ft_strjoin_char(word, line[i]); */
			/* 	i++; */
			/* } */
			/* i++; */
		}
		else if (quote && (line[i] == '\'' || line[i] == '"'))
			quote = false;
		/* else */
		/* { */
		word = ft_strjoin_char(word, line[i]);
		i++;
		/* } */
	}
	add_token(&tokens, word);
	free(word);
	return (i - 1);
}

char	**tokenize(char *line)
{
	char	**tokens;
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
			;
		else if (line[i] == '|')
			add_token(&tokens, "|");
		else if (line[i] == '<' && line[i + 1] == '<' && line[i++])
			add_token(&tokens, "<<");
		else if (line[i] == '>' && line[i + 1] == '>' && line[i++])
			add_token(&tokens, ">>");
		else if (line[i] == '<')
			add_token(&tokens, "<");
		else if (line[i] == '>')
			add_token(&tokens, ">");
		/* else if (line[i] == '\'' || line[i] == '"') */
		/* 	i += quote_token(line + i, tokens); */
		/* else if (line[i] == '$') */
		/* 	i += word_token(env_var_value(line + i)); */
		else
			i += word_token(line + i, tokens);
	}
	i = -1;
	while (tokens[++i] != NULL)
		printf("%s\n", tokens[i]);
	return (tokens);
}
