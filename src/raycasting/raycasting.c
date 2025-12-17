/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:25:03 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/15 18:25:05 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// calculate the initial of the ray
void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)g->win_w - 1;
	r->ray_dir_x = g->player.dir_x + g->player.plane_x * r->camera_x;
	r->ray_dir_y = g->player.dir_y + g->player.plane_y * r->camera_x;
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->hit = 0;
}

t_tex	*select_wall_texture(t_game *g, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			return (&g->config.tex_west);
		else
			return (&g->config.tex_east);
	}
	else
	{
		if (r->ray_dir_y > 0)
			return (&g->config.tex_north);
		else
			return (&g->config.tex_south);
	}
}

void	raycast_scene(t_game *g)
{
	int		x;
	t_ray	ray;
	t_tex	*tex;

	x = 0;
	while (x < g->win_w)
	{
		init_ray(g, &ray, x);
		perform_dda(g, &ray);
		compute_wall(g, &ray);
		tex = select_wall_texture(g, &ray);
		compute_tex_x(g, &ray, tex);
		draw_column(g, &ray, x);
		x++;
	}
}
