/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:45 by root              #+#    #+#             */
/*   Updated: 2025/03/08 03:22:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strjoin_gnl(char *stash, char *buf)
{
	int		i;
	int		j;
	int		total_len;
	char	*new_stash;

	if (!stash && !buf)
		return (NULL);
	total_len = ft_strlen_gnl(stash) + ft_strlen_gnl(buf);
	new_stash = malloc(sizeof(char) * (total_len + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	j = 0;
	while (stash && stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (buf[j])
		new_stash[i++] = buf[j++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*line_cpy(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (dst);
}

void	stash_cleanup(char **stash)
{
	int		i;
	int		j;
	char	*trimmed_line;

	i = 0;
	j = 0;
	if (!(*stash)[i])
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	i++;
	trimmed_line = malloc(sizeof(char) * (ft_strlen_gnl(*stash) - i + 1));
	if (!trimmed_line)
		return ;
	while ((*stash)[i])
		trimmed_line[j++] = (*stash)[i++];
	trimmed_line[j] = '\0';
	free(*stash);
	*stash = trimmed_line;
	// free(trimmed_line);
}
