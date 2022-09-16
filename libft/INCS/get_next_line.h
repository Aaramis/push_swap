/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:46:39 by agardett          #+#    #+#             */
/*   Updated: 2022/05/27 21:47:10 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE__H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"

# define BUFFER_SIZE 2048

char	*get_next_line(int fd);
char	*ft_ccalloc(size_t nmemb, size_t size);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_findline(char *buff_f);

#endif
