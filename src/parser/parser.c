/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:39:53 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 18:14:19 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_ast(char **tokens, int start, int end)
{
	while (end == start)
	{
		end--;
	}
}

t_ast	*parsing(char **tokens)
{
	t_ast	*ast;

	(void)ast;
	build_ast(tokens, 0, 0);
	return (ast);
}
