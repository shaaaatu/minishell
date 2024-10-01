/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:09:48 by luebina           #+#    #+#             */
/*   Updated: 2024/10/01 20:55:10 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_token	*tokens;

	(void)argc;
	(void)argv;
	tokens = NULL;
	rl_outstream = stderr;
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			free(line);
			break ;
		}
		if (*line)
			add_history(line);
		tokenize(line, &tokens);
		free(line);
	}
	clear_tokens(&tokens);
	exit(0);
	return (0);
}
