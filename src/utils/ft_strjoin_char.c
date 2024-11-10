/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:39:47 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 16:39:54 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_char(char *s1, char c)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	if (new_str == NULL)
		return (NULL);
	if (s1)
		ft_strlcpy(new_str, s1, len + 1);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(s1);
	return (new_str);
}
