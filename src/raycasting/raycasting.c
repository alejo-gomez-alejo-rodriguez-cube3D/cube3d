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

void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2.0 * x / (double)g->win_w - 1.0;
	r->ray_dir_x = g->player.dir_x + g->player.plane_x * r->camera_x;
	r->ray_dir_y = g->player.dir_y + g->player.plane_y * r->camera_x;
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
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

void	init_step(t_game *g, t_ray *r)
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

void	raycast_scene(t_game *g)
{
	int		x;
	t_ray	ray;
	t_tex	*tex;

	x = 0;
	while (x < g->win_w)
	{
		init_ray(g, &ray, x);
		init_step(g, &ray);
		perform_dda(g, &ray);
		compute_wall(g, &ray);
		tex = select_wall_texture(g, &ray);
		compute_tex_x(g, &ray, tex);
		draw_column(g, &ray, x);
		x++;
	}
}
