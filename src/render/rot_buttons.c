/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_buttons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:48:45 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 17:48:47 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	rotate_left(t_game *g)
{
	double	frame_rot;
	double	old_dir_x;
	double	old_plane_x;

	frame_rot = g->rot_speed * g->delta_time;
	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(frame_rot) - g->player.dir_y
		* sin(frame_rot);
	g->player.dir_y = old_dir_x * sin(frame_rot) + g->player.dir_y
		* cos(frame_rot);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(frame_rot) - g->player.plane_y
		* sin(frame_rot);
	g->player.plane_y = old_plane_x * sin(frame_rot) + g->player.plane_y
		* cos(frame_rot);
}

void	rotate_right(t_game *g)
{
	double	frame_rot;
	double	old_dir_x;
	double	old_plane_x;

	frame_rot = g->rot_speed * g->delta_time;
	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-frame_rot) - g->player.dir_y
		* sin(-frame_rot);
	g->player.dir_y = old_dir_x * sin(-frame_rot) + g->player.dir_y
		* cos(-frame_rot);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-frame_rot) - g->player.plane_y
		* sin(-frame_rot);
	g->player.plane_y = old_plane_x * sin(-frame_rot) + g->player.plane_y
		* cos(-frame_rot);
}
