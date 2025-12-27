/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:02:34 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 18:02:36 by alejandro        ###   ########.fr       */
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

static int	flood_fill(char **map, int x, int y, int rows, int cols)
{
	if (y < 0 || y >= rows || x < 0 || x >= cols)
		return (1);

	if (map[y][x] == ' ')
		return (1);

	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);

	map[y][x] = 'V';

	if (flood_fill(map, x + 1, y, rows, cols) == 1 ||
		flood_fill(map, x - 1, y, rows, cols) == 1 || 
		flood_fill(map, x, y + 1, rows, cols) == 1 || 
		flood_fill(map, x, y - 1, rows, cols) == 1)
		return (1);

	return (0);
}

int	check_walls(t_game *game)
{
	char	**temp_map;
	int		result;

	temp_map = copy_map(game);
	if (!temp_map)
		return (print_error("Memory allocation failed for map validation"));

	result = flood_fill(temp_map, (int)game->player.x, (int)game->player.y, 
						game->map.rows, game->map.cols);

	free_map_copy(temp_map);

	if (result == 1)
		return (print_error("Map is not closed/surrounded by walls"));
	
	return (0);
}
