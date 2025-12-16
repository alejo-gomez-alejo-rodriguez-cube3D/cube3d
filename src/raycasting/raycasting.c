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

// dibuja la columna simple
void draw_column(t_game *g, t_ray *r, int x)
{
    int y;
    int color;

    color = (r->side == 1) ? 0xAAAAAA : 0xFFFFFF;

    y = r->draw_start;
    while (y < r->draw_end)
    {
        put_pixel(&g->screen, x, y, color);
        y++;
    }
}

// calcula distancia y altura
void compute_wall(t_game *g, t_ray *r)
{
    if (r->side == 0)
        r->perp_wall_dist =
            r->side_dist_x - r->delta_dist_x;
    else
        r->perp_wall_dist =
            r->side_dist_y - r->delta_dist_y;

    r->line_height =
        (int)(g->win_h / r->perp_wall_dist);

    r->draw_start =
        -r->line_height / 2 + g->win_h / 2;
    if (r->draw_start < 0)
        r->draw_start = 0;

    r->draw_end =
        r->line_height / 2 + g->win_h / 2;
    if (r->draw_end >= g->win_h)
        r->draw_end = g->win_h - 1;
}

// avanza el rayo hasta chocar con una pared
void perform_dda(t_game *g, t_ray *r)
{
    if (r->ray_dir_x < 0)
    {
        r->step_x = -1;
        r->side_dist_x =
            (g->player.x - r->map_x) * r->delta_dist_x;
    }
    else
    {
        r->step_x = 1;
        r->side_dist_x =
            (r->map_x + 1.0 - g->player.x) * r->delta_dist_x;
    }

    if (r->ray_dir_y < 0)
    {
        r->step_y = -1;
        r->side_dist_y =
            (g->player.y - r->map_y) * r->delta_dist_y;
    }
    else
    {
        r->step_y = 1;
        r->side_dist_y =
            (r->map_y + 1.0 - g->player.y) * r->delta_dist_y;
    }

    while (!r->hit)
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

        if (g->map.map[r->map_y][r->map_x] == '1')
            r->hit = 1;
    }
}

// calculate the initial of the ray
void	init_ray(t_game *g, t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)g->win_w -1;
	r->ray_dir_x = g->player.dir_x + g->player.plane_x * r->camera_x;
	r->ray_dir_y = g->player.dir_y + g->player.plane_y * r->camera_x;
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	r->hit = 0;
}

void	raycast_scene(t_game *g)
{
	int	x;
	t_ray	ray;

	x = 0;
	while (x < g->win_w)
	{
		init_ray(g, &ray, x);
		perform_dda(g, &ray);
		compute_wall(g, &ray);
		draw_column(g, &ray, x);
		x++;
	}
}
