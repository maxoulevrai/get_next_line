/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:31 by root              #+#    #+#             */
/*   Updated: 2025/02/27 20:33:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strndup(char *src, size_t siz);
size_t	gnl_len(void *buf);


#endif
