/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:56 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/20 12:57:57 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dub;

	len = ft_strlen(s) + 1;
	dub = malloc(len);
	if (!dub)
		return (NULL);
	ft_strlcpy(dub, s, len);
	return (dub);
}

/*int	main(void)
{
	char uv[] = "hola";
	char *duplicado = ft_strdup(uv);

	printf("Cadena original: %s\n", uv);
	printf("Cadena duplicada: %s\n", duplicado);
}*/