/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:12:54 by maleca            #+#    #+#             */
/*   Updated: 2025/05/12 20:52:31 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *str, char c);
void	stash_cleanup(char **stash);
char	*read_and_store(int fd, char *stash, int *flag);
size_t	gnl_len(char *str);
char	*ft_strjoin_gnl(char *stash, char *buff);

#endif