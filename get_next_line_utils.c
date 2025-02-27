/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:45 by root              #+#    #+#             */
/*   Updated: 2025/02/27 20:33:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_len(void *buf)
{
	size_t	i;

	i = 0;
	while (((char *)buf)[i] != '\n')
		i++;
	return (i);
}

char	*ft_strndup(char *src, size_t siz)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char) * siz + 1);
	if (!dst)
		return (NULL);
	while (src[i] && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

