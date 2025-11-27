/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:50:57 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/20 12:56:35 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

/*int	main(void)
{
	int		*i;
	size_t	n;

	i = ft_calloc(8, sizeof(int));
	n = 0;
	while (n < 8)
	{
		printf("%d\n", i[n]);
		n++;
	}
}*/
