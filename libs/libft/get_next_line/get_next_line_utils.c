/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:58:20 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/21 12:46:46 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	lens;
	size_t	i;

	src_len = ft_strlen_gnl(src);
	dst_len = ft_strlen_gnl(dst);
	lens = src_len + dst_len;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (lens);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src && src[j] != '\0')
		j++;
	if (size > 0)
	{
		while (i < size - 1 && src && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy_gnl(p, s1, ft_strlen_gnl(s1) + 1);
	ft_strlcat_gnl(p, s2, len + 1);
	free((char *)s1);
	return (p);
}
