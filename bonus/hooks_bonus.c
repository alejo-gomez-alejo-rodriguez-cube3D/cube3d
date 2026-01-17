/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:33:14 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/16 21:24:07 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus.h"

int	init_game_bonus(t_game *g)
{
	init_constants(g);
	if (init_mlx(g))
		return (1);
	g->mlx_initialized = 1;
	mlx_mouse_hide(g->img_mlx, g->window);
	mlx_mouse_move(g->img_mlx, g->window, g->win_w / 2, g->win_h / 2);
	g->mouse_x = g->win_w / 2;
	g->mouse_initialized = 0;
	if (load_all_textures(g))
		return (1);
	return (0);
}

void	set_hook_bonus(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_hook(game->window, 6, 1L << 6, mouse_move, game);
}

int	mouse_move(int x, int y, t_game *g)
{
	int		delta_x;
	double	angle;

	(void)y;
	if (!g->mouse_initialized)
	{
		g->mouse_x = x;
		g->mouse_initialized = 1;
		return (0);
	}
	delta_x = x - g->mouse_x;
	g->mouse_x = x;
	angle = delta_x * MOUSE_SENS * g->delta_time;
	rotate_by_angle(g, angle);
	return (0);
}
