/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:30:36 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/08 15:39:18 by alejaro2         ###   ########.fr       */
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

/*
** Función auxiliar: Decide qué color pintar basándose en la posición del mapa
*/
static int	get_minimap_pixel_color(t_game *game, double x, double y)
{
	if (x < 0 || x >= game->map.cols || y < 0 || y >= game->map.rows)
		return (C_MM_BG);
	if (game->map.map[(int)y][(int)x] == '1')
		return (C_MM_WALL);
	if (game->map.map[(int)y][(int)x] != ' ')
		return (C_MM_FLOOR);
	return (C_MM_BG);
}

void	draw_minimap(t_game *game)
{
	int		s_x;
	int		s_y;
	double	m_x;
	double	m_y;
	int		color;

	draw_minimap_border(game);
	s_y = -1;
	while (++s_y < MM_SIZE)
	{
		s_x = -1;
		while (++s_x < MM_SIZE)
		{
			m_x = game->player.x + (s_x - (MM_SIZE / 2)) / MM_ZOOM;
			m_y = game->player.y + (s_y - (MM_SIZE / 2)) / MM_ZOOM;
			color = get_minimap_pixel_color(game, m_x, m_y);
			if (color != C_MM_BG)
				put_pixel(&game->screen, MM_OFFSET_X + s_x, MM_OFFSET_Y + s_y,
					color);
		}
	}
	draw_player_center(game);
}
