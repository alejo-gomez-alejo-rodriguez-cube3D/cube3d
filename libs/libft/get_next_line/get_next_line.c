/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:18:42 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/21 11:03:53 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*updated_accumulated(char *accumulated)
{
	char	*ptr;
	char	*temp;
	int		len;
	int		i;

	ptr = ft_strchr_gnl(accumulated, '\n');
	if (ptr != NULL)
		len = ft_strlen_gnl(ptr + 1);
	else
		return (NULL);
	if (len == 0)
		return (NULL);
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ptr++;
	i = 0;
	while (i < len)
	{
		temp[i] = ptr[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*extract_line(char *accumulated)
{
	char	*ptr;
	char	*line;
	size_t	len;

	if (!accumulated)
		return (NULL);
	ptr = ft_strchr_gnl(accumulated, '\n');
	if (ptr != NULL)
		len = (ptr - accumulated) + 1;
	else
		len = ft_strlen_gnl(accumulated);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return ((free(line)), NULL);
	ft_strlcpy_gnl(line, accumulated, len + 1);
	line[len] = 0;
	return (line);
}

char	*read_until(int fd, char *accumulated)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(accumulated), NULL);
	bytes = 1;
	while (ft_strchr_gnl(accumulated, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return ((free(accumulated), free(buffer), NULL));
		if (bytes == 0)
			return (free(buffer), accumulated);
		buffer[bytes] = '\0';
		accumulated = ft_strjoin_gnl(accumulated, buffer);
		if (!accumulated)
			return (free(buffer), NULL);
	}
	return (free(buffer), accumulated);
}


char	*get_next_line(int fd)
{
	static char	*accumulated;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulated = read_until(fd, accumulated);
	if (!accumulated)
		return (NULL);
	line = extract_line(accumulated);
	temp = updated_accumulated(accumulated);
	free(accumulated);
	accumulated = temp;
	return (line);
}

