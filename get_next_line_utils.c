/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:45 by root              #+#    #+#             */
/*   Updated: 2025/03/07 17:20:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	ft_strcat(char *src, char *dst)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen_gnl(dst);
	if (!dst)
	{
		dst = malloc(sizeof(char) * ft_strlen_gnl(src) + ft_strlen_gnl(dst) + 1);
		dst[0] = '\0';
	}
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

void	stash_cleanup(char **stash)
{
	int		i;
	int		j;
	char	*trimmed_line;

	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if (!(*stash)[i])
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	i++;
	trimmed_line = malloc(sizeof(char) * (ft_strlen_gnl(*stash) - i + 1));
	if (!trimmed_line)
		return ;
	while ((*stash)[i])
		trimmed_line[j++] = (*stash)[i++];
	trimmed_line[j] = '\0';
	free(*stash);
	*stash = trimmed_line;
}
