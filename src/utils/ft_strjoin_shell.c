/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:39:18 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 16:39:30 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_shell(char *s1, char *s2)
{
	char	*ptr;

	if (!s2)
		return (NULL);
	if (s1)
	{
		ptr = ft_strjoin(s1, s2);
		free(s1);
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s2, ft_strlen(s2) + 1);
	return (ptr);
}
