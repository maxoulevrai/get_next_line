/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:19:53 by root              #+#    #+#             */
/*   Updated: 2025/02/27 20:34:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*next_line;
	static int	count;
	size_t	siz;

	siz = read(fd, buf, BUFFER_SIZE);
	if (!buf)
		return (NULL);
	next_line = malloc(sizeof(char) * siz + 1);
	if (!next_line)
		return (NULL);
	next_line = ft_strndup(buf, siz);
	count++;
	return (next_line);
}

int	main(void)
{
	
}