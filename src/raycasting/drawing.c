/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:38:04 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/17 17:38:05 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// dibujar techo
void	draw_ceiling(t_game *g, int x, int end)
{
	int	y;

	y = 0;
	while (y < end)
	{
		put_pixel(&g->screen, x, y, g->config.color_ceiling);
		y++;
	}
}

// dibujar suelo
void	draw_floor(t_game *g, int x, int start)
{
	int	y;

	y = start;
	while (y < g->win_h)
	{
		put_pixel(&g->screen, x, y, g->config.color_floor);
		y++;
	}
}

// dibujar la pared texturizada
void	draw_wall(t_game *g, t_ray *r, t_tex *tex, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex_y = (int)r->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		r->tex_pos += r->tex_step;
		color = get_tex_pixel(tex, r->tex_x, tex_y);
		put_pixel(&g->screen, x, y, color);
		y++;
	}
}

// funcion central del renderizado
void	draw_column(t_game *g, t_ray *r, int x)
{
	t_tex	*tex;

	tex = select_wall_texture(g, r);
	draw_ceiling(g, x, r->draw_start);
	draw_wall(g, r, tex, x);
	draw_floor(g, x, r->draw_end);
}
