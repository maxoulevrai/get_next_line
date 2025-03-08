/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:19:53 by root              #+#    #+#             */
/*   Updated: 2025/03/08 22:50:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
		i++;
	return (i);
}

static int	is_line_complete(char *stash)
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

static void	*ft_calloc(size_t nmemb, size_t siz)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = NULL;
	if (siz && nmemb > (UINT_MAX / siz))
		return (NULL);
	mem = malloc(nmemb * siz);
	if (!mem)
		return (NULL);
	while (i < siz)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*next_line;
	char		*buf;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	read_bytes = 1;
	while (!is_line_complete(stash) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buf), NULL);
		buf[read_bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
	}
	free(buf);
	if (!stash || *stash == '\0')
		return (NULL);
	next_line = line_cpy(stash);
	stash_cleanup(&stash);
	return (next_line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = 12;
	char	*next_line;

	// fd = open("fichier_alr.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	close(fd);
	return (0);
}
