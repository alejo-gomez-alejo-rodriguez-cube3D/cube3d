/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:05:25 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/08 15:43:59 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
