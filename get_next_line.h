/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:03:31 by root              #+#    #+#             */
/*   Updated: 2025/03/08 20:38:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *stash);
char	*get_next_line(int fd);
char	*line_cpy(char *src);
void	*ft_strjoin_gnl(char *stash, char *buf);
void	stash_cleanup(char **stash);

#endif
