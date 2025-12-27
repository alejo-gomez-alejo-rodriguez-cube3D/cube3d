/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:02:54 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 18:02:57 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_max_width(char **map)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static char	*fill_line_with_spaces(char *line, int width)
{
	char	*new_line;
	int		len;
	int		i;

	len = ft_strlen(line);
	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	make_map_rectangular(t_game *game)
{
	int		width;
	int		i;
	char	*new_line;

	width = get_max_width(game->map.map);
	game->map.cols = width;
	i = 0;
	while (game->map.map[i])
	{
		if ((int)ft_strlen(game->map.map[i]) < width)
		{
			new_line = fill_line_with_spaces(game->map.map[i], width);
			if (!new_line)
				return (print_error("Memory error making map rectangular"));
			free(game->map.map[i]);
			game->map.map[i] = new_line;
		}
		i++;
	}
	return (0);
}
