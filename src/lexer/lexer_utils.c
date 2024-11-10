/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:11:11 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 16:40:56 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(char ***tokens, char *value)
{
	int		i;

	i = 0;
	if (!*tokens)
	{
		*tokens = (char **)malloc(sizeof(char *) * 2);
		(*tokens)[0] = ft_strdup(value);
		(*tokens)[1] = NULL;
		return ;
	}
	while ((*tokens)[i] != NULL)
		i++;
	*tokens = (char **)ft_realloc(*tokens, sizeof(char *) * (i + 2), sizeof(char *) * (i + 3));
	(*tokens)[i] = ft_strdup(value);
	if ((*tokens)[i] == NULL)
		return ;
	(*tokens)[i + 1] = NULL;
	return ;
}
