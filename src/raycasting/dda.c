/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:23:37 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/16 19:23:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// Initializes DDA step and initial side distance for the X axis.
void	init_dda_x(t_game *g, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->player.x) * r->delta_dist_x;
	}
}

// Initializes DDA step and initial side distance for the Y axis.
void	init_dda_y(t_game *g, t_ray *r)
{
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->player.y) * r->delta_dist_y;
	}
}

// Advances the ray through the map grid until a wall is hit.
// Chooses the next grid cell based on the closest side distance.
void	dda_loop(t_game *g, t_ray *r)
{
	char	cell;

	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		cell = g->map.map[r->map_y][r->map_x];
		if (cell == '1' || (cell == 'D'
				&& is_door_close(g, r->map_x, r->map_y)))
			r->hit = 1;
	}
}

// Prepares and executes the DDA algorithm to detect wall collision.
void	perform_dda(t_game *g, t_ray *r)
{
	init_dda_x(g, r);
	init_dda_y(g, r);
	dda_loop(g, r);
}
