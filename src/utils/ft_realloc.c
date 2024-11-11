/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luebina <luebina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:23 by luebina           #+#    #+#             */
/*   Updated: 2024/11/10 18:55:32 by luebina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ternaries(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (ptr == NULL)
		return (malloc(new_size));
	printf("5\n");
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	printf("6\n");
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	printf("7\n");
	copy_size = ternaries(old_size, new_size);
	printf("8\n");
	ft_memcpy(new_ptr, ptr, copy_size);
	printf("9\n");
	free(ptr);
	printf("10\n");
	return (new_ptr);
}
