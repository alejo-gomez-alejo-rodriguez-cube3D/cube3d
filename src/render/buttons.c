/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:17:41 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/11 17:17:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	move_backward(t_game *g)
{
	double	frame_move;
	double	new_x;
	double	new_y;

	frame_move = g->move_speed * g->delta_time;
	new_x = g->player.x - g->player.dir_x * frame_move;
	new_y = g->player.y - g->player.dir_y * frame_move;
	if (g->map.map[(int)g->player.y][(int)(new_x - g->player.dir_x
		* WALL_MARGIN)] != '1')
		g->player.x = new_x;
	if (g->map.map[(int)(new_y - g->player.dir_y
			* WALL_MARGIN)][(int)g->player.x] != '1')
		g->player.y = new_y;
}

void	move_forward(t_game *g)
{
	double	frame_move;
	double	new_x;
	double	new_y;

	frame_move = g->move_speed * g->delta_time;
	new_x = g->player.x + g->player.dir_x * frame_move;
	new_y = g->player.y + g->player.dir_y * frame_move;
	if (g->map.map[(int)g->player.y][(int)(new_x + g->player.dir_x
		* WALL_MARGIN)] != '1')
		g->player.x = new_x;
	if (g->map.map[(int)(new_y + g->player.dir_y
			* WALL_MARGIN)][(int)g->player.x] != '1')
		g->player.y = new_y;
}

void	strafe_left(t_game *g)
{
	double	frame_move;
	double	new_x;
	double	new_y;

	frame_move = g->move_speed * g->delta_time;
	new_x = g->player.x - g->player.dir_y * frame_move;
	new_y = g->player.y + g->player.dir_x * frame_move;
	if (g->map.map[(int)g->player.y][(int)(new_x - g->player.dir_y
		* WALL_MARGIN)] != '1')
		g->player.x = new_x;
	if (g->map.map[(int)(new_y + g->player.dir_x
			* WALL_MARGIN)][(int)g->player.x] != '1')
		g->player.y = new_y;
}

void	strafe_right(t_game *g)
{
	double	frame_move;
	double	new_x;
	double	new_y;

	frame_move = g->move_speed * g->delta_time;
	new_x = g->player.x + g->player.dir_y * frame_move;
	new_y = g->player.y - g->player.dir_x * frame_move;
	if (g->map.map[(int)g->player.y][(int)(new_x + g->player.dir_y
		* WALL_MARGIN)] != '1')
		g->player.x = new_x;
	if (g->map.map[(int)(new_y - g->player.dir_x
			* WALL_MARGIN)][(int)g->player.x] != '1')
		g->player.y = new_y;
}
