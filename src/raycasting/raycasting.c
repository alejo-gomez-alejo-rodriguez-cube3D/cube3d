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
    int ceil_color = g->config.color_ceiling;
    int floor_color = g->config.color_floor;
    t_tex *tex = select_wall_texture(g, r);  // Elegir la textura

    // 🟦 TECHO
    y = 0;
    while (y < r->draw_start)
    {
        put_pixel(&g->screen, x, y, ceil_color);
        y++;
    }

    // 🟩 PARED (con textura)
    y = r->draw_start;
    while (y < r->draw_end)
    {
        // Calculamos la posición de la textura
        int tex_y = (int)((y - r->draw_start) * tex->height / r->line_height);

        // Obtener el color de la textura para cada pixel
        color = get_tex_pixel(tex, r->tex_x, tex_y);  // Usamos `tex_x` y `tex_y`
        
        put_pixel(&g->screen, x, y, color);  // Dibujar el color de la textura
        y++;
    }

    // 🟫 SUELO
    y = r->draw_end;
    while (y < g->win_h)
    {
        put_pixel(&g->screen, x, y, floor_color);
        y++;
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

void compute_tex_x(t_game *g, t_ray *r, t_tex *tex)
{
    double wall_x;

    if (r->side == 0)
        wall_x = g->player.y + r->perp_wall_dist * r->ray_dir_y;
    else
        wall_x = g->player.x + r->perp_wall_dist * r->ray_dir_x;

    wall_x -= floor(wall_x);

    r->tex_x = (int)(wall_x * tex->width);

    if (r->side == 0 && r->ray_dir_x > 0)
        r->tex_x = tex->width - r->tex_x - 1;
    if (r->side == 1 && r->ray_dir_y < 0)
        r->tex_x = tex->width - r->tex_x - 1;
}

t_tex *select_wall_texture(t_game *g, t_ray *r)
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
	int	x;
	t_ray	ray;
    t_tex *tex;

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
