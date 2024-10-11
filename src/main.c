/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:09:48 by luebina           #+#    #+#             */
/*   Updated: 2024/10/09 16:49:55 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	t_token	*tokens;

	rl_outstream = stderr;
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
		tokenize(line, &tokens);
		command(tokens);
		free(line);
		clear_tokens(&tokens);
	}
	exit(0);
	return (0);
}
