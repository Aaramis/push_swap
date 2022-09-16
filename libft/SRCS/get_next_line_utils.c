/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:47:24 by agardett          #+#    #+#             */
/*   Updated: 2022/06/02 20:58:28 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ccalloc(size_t nmemb, size_t size)
{
	char	*str;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero((void *)str, (nmemb * size));
	return (str);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest || !s1 || !s2)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[size] = 0;
	free(s1);
	return (dest);
}
