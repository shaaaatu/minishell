/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:26:14 by luebina           #+#    #+#             */
/*   Updated: 2024/10/01 22:47:00 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_char(char *s1, char c)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = malloc(len + 2);
	if (new_str == NULL)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(new_str, s1, len + 1);
	}
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(s1);
	return (new_str);
}

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

char	*ft_strndup(const char *s, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] && i < size)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
