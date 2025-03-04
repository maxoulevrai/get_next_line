/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:19:53 by root              #+#    #+#             */
/*   Updated: 2025/03/04 03:04:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*next_line;
	char		buf[BUFFER_SIZE + 1];
	int			read_bytes;

	if (BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (!is_line_complete(stash) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		ft_strcat(buf, stash);
	}
	next_line = line_cpy(stash);
	stash_cleanup(stash);
	return (next_line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("fichier_alr.txt", O_RDWR);
	char	*next_line;

	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	free(next_line);
	return (0);	
}