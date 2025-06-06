/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:00:47 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 17:26:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_line(char *stash);
char	*ft_save_stash(char *stash);
char	*ft_read_fd(int fd, char *stash);
char	*get_next_line(int fd);

#endif
