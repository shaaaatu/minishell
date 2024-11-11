/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:09:48 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 18:50:43 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	char	**tokens;
	t_ast	*ast;
	int		i;

	rl_outstream = stderr;
	tokens = NULL;
	while (1)
	{
		tokens = NULL;
		line = readline("minishell$ ");
		if (line == NULL)
		{
			free(line);
			break ;
		}
		if (*line)
			add_history(line);
		printf("tokens\n");
		tokens = tokenize(line);
		i = -1;
		while (tokens[++i] != NULL)
			printf("%s\n", tokens[i]);
		/* ast = parsing(tokens); */
		(void)ast;
		break ;
		/* command(tokens); */
		/* free(line); */
		/* clear_tokens(&tokens); */
	}
	exit(0);
	return (0);
}
