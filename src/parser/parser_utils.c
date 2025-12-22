/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:25:56 by alejaro2          #+#    #+#             */
/*   Updated: 2025/12/18 18:26:22 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*skip_spaces(char *line)
{
	while (line && *line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

int	is_empty_line(char *line)
{
	char	*ptr;

	ptr = skip_spaces(line);
	if (!*ptr || *ptr == '\n')
		return (1);
	return (0);
}

int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (1);
}
