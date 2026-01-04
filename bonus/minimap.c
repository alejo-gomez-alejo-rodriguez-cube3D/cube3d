/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:30:36 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/05 00:07:27 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* bonus/minimap.c */

#include "bonus.h"

static void	draw_minimap_border(t_game *game)
{
	int	x;
	int	y;

	y = MM_OFFSET_Y - 2;
	while (y < MM_OFFSET_Y + MM_SIZE + 2)
	{
		x = MM_OFFSET_X - 2;
		while (x < MM_OFFSET_X + MM_SIZE + 2)
		{
			if (x < MM_OFFSET_X || x >= MM_OFFSET_X + MM_SIZE || y < MM_OFFSET_Y
				|| y >= MM_OFFSET_Y + MM_SIZE)
			{
				put_pixel(&game->screen, x, y, C_MM_FRAME);
			}
			x++;
		}
		y++;
	}
}

static void	draw_player_center(t_game *game)
{
	int	center_x;
	int	center_y;
	int	i;
	int	j;

	center_x = MM_OFFSET_X + (MM_SIZE / 2);
	center_y = MM_OFFSET_Y + (MM_SIZE / 2);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(&game->screen, center_x + j, center_y + i, C_MM_PLAYER);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int screen_x;
	int screen_y;
	double map_x;
	double map_y;
	int color;

	draw_minimap_border(game);

	screen_y = 0;
	while (screen_y < MM_SIZE)
	{
		screen_x = 0;
		while (screen_x < MM_SIZE)
		{
			map_x = game->player.x + (screen_x - (MM_SIZE / 2)) / MM_ZOOM;
			map_y = game->player.y + (screen_y - (MM_SIZE / 2)) / MM_ZOOM;

			color = C_MM_BG;
			if (map_x >= 0 && map_x < game->map.cols && map_y >= 0
				&& map_y < game->map.rows)
			{
				if (game->map.map[(int)map_y][(int)map_x] == '1')
					color = C_MM_WALL;
				else if (game->map.map[(int)map_y][(int)map_x] != ' ')
					color = C_MM_FLOOR;
			}
			if (color != C_MM_BG)
			{
				put_pixel(&game->screen, MM_OFFSET_X + screen_x, MM_OFFSET_Y
					+ screen_y, color);
			}

			screen_x++;
		}
		screen_y++;
	}
	draw_player_center(game);
}
