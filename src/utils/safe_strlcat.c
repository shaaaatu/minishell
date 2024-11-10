/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:38:08 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 16:38:21 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	safe_strlcat(char **dest, const char *src, size_t n)
{
	if (!*dest)
	{
		*dest = (char *)malloc(sizeof(char) * (n + 1));
		if (!*dest)
			return (0);
		*dest[0] = '\0';
	}
	return (ft_strlcat(*dest, src, n + 1));
}
