/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:51:47 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/17 17:51:48 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	step_ray(t_ray *r)
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
}

static int	check_hit(t_game *g, t_ray *r)
{
	char	cell;

	cell = g->map.map[r->map_y][r->map_x];
	if (cell == '1')
	{
		r->hit_door = 0;
		return (1);
	}
	if (cell == 'D' && is_door_close(g, r->map_x, r->map_y))
	{
		r->hit_door = 1;
		return (1);
	}
	return (0);
}

void	dda_loop(t_game *g, t_ray *r)
{
	while (!r->hit)
	{
		step_ray(r);
		if (check_hit(g, r))
			r->hit = 1;
	}
}
