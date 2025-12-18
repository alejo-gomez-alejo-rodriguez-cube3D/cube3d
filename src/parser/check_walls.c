/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:30:03 by alejaro2          #+#    #+#             */
/*   Updated: 2025/12/18 18:48:20 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (game->map.map[i])
	{
		copy[i] = ft_strdup(game->map.map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	flood_fill(t_map *map_info, int x, int y)
{
	if (y < 0 || y >= map_info->rows || x < 0 || x >= map_info->cols)
		return (1);
	if (map_info->map[y][x] == ' ')
		return (1);
	if (map_info->map[y][x] == '1' || map_info->map[y][x] == 'V')
		return (0);
	map_info->map[y][x] = 'V';
	if (flood_fill(map_info, x + 1, y) == 1 || flood_fill(map_info, x - 1,
			y) == 1 || flood_fill(map_info, x, y + 1) == 1
		|| flood_fill(map_info, x, y - 1) == 1)
		return (1);
	return (0);
}

int	check_walls(t_game *game)
{
	t_map	validator;
	int		result;

	validator.map = copy_map(game);
	if (!validator.map)
		return (print_error("Memory allocation failed for map validation"));
	validator.rows = game->map.rows;
	validator.cols = game->map.cols;
	result = flood_fill(&validator, (int)game->player.x, (int)game->player.y);
	free_map_copy(validator.map);
	if (result == 1)
		return (print_error("Map is not closed/surrounded by walls"));
	return (0);
}
