/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:01:50 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 18:01:52 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	save_player_pos(t_game *game, int x, int y)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	game->player.dir_char = game->map.map[y][x];
	game->map.map[y][x] = '0';
}

static int	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (!is_valid_char(game->map.map[i][j]))
				return (print_error("Invalid character"));
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_player_count(t_game *game)
{
	int		i;
	int		j;
	int		count;
	char	c;

	i = -1;
	count = 0;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			c = game->map.map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				count++;
				save_player_pos(game, j, i);
			}
		}
	}
	if (count != 1)
		return (print_error("Map must have exactly one player"));
	return (0);
}

int	validate_map(t_game *game)
{
	if (check_map_chars(game) != 0)
		return (1);
	if (check_player_count(game) != 0)
		return (1);
    if (make_map_rectangular(game) != 0)
		return (1);
	if (check_walls(game) != 0)
        return (1);
	return (0);
}
