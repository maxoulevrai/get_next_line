/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:07:45 by root              #+#    #+#             */
/*   Updated: 2025/03/03 04:38:42 by root             ###   ########.fr       */
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

char	*ft_strcpy_line(char *stash)
{
	int		i;
	char	*line;

	
	i = 0;
	line = NULL;
	if (!stash)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen_gnl(stash) + 1));
	if (!line)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_stash_cleanup(char *stash)
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
	}
	return (trimmed_line);
}
