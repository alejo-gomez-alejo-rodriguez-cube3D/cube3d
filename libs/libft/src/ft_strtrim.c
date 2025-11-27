/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:23:04 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/20 12:58:54 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*p;

	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strrchr(set, s1[end]))
		end--;
	p = ft_substr(s1, start, end - start + 1);
	return (p);
}

/*int main(void)
{
	char const in[] = "***";
	char const on[] = "*";

	printf("nueva: %s", ft_strtrim(in, on));
}*/