/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:39:53 by luebina           #+#    #+#             */
/*   Updated: 2024/11/13 20:23:21 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*create_node(char *value)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	node->value = ft_strndup(value, ft_strlen(value));
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_op_precedence	get_precedence(char *token)
{
	if (ft_strncmp(token, "&&", 2) == 0 || ft_strncmp(token, "||", 2) == 0)
		return (AND_OR);
	else if (ft_strncmp(token, "|", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(token, ">", 2) == 0 || ft_strncmp(token, ">>", 2) == 0
			|| ft_strncmp(token, "<", 2) == 0 || ft_strncmp(token, "<<", 2) == 0)
		return (REDIR);
	else
		return (WORD);
}

t_ast	*build_ast(char **tokens, int start, int end)
{
	t_op_precedence op;
	/* t_op_precedence	token_op; */
	int				i;
	t_ast			*node;

	op = AND_OR;
	while (op <= REDIR)
	{
		i = end;
		while (i > start)
		{
			if (get_precedence(tokens[end]) == op)
			{
				node = create_node(tokens[i]);
				node->left = build_ast(tokens, start, i - 1);
				node->right = build_ast(tokens, i + 1, end);
				return (node);
			}
			i--;
		}
		op++;
	}
	return (create_node(tokens[start]));
}

t_ast	*parsing(char **tokens)
{
	t_ast	*ast;
	int		i;

	ast = NULL;
	i = 0;
	(void)ast;
	while (tokens[i])
		i++;
	build_ast(tokens, 0, i - 1);
	(void)tokens;
	return (ast);
}
