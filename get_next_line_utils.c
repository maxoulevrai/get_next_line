/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:45 by root              #+#    #+#             */
/*   Updated: 2025/03/04 03:04:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (i);
}

int	is_line_complete(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
void	ft_strcat(char *src, char *dst)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen_gnl(dst);
	while (src[j] && src[j] != '\n')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
}

char	*line_cpy(char *src)
{
	int		i;
	char	*dst;
	
	i = 0;
	dst = NULL;
	if (!src)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen_gnl(src) + 1));
	if (!dst)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	stash_cleanup(char *stash)
{
	int		i;
	int		j;
	char	*trimmed_line;
	
	i = 0;
	j = 0;
	trimmed_line = NULL;
	while (stash[i] != '\n')
		i++;
	i++;
	while (stash[i])
	{
		trimmed_line[j] = stash[i];
		i++;
	}
	trimmed_line[i] = '\0';
}
