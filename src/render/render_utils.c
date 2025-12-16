/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:39:48 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/12 17:39:50 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// textura temporal, reemplazar por el raycasting
void	blit_texture_center(t_game *g, t_tex *tex)
{
	int				start_x;
	int				start_y;
	unsigned int	color;

	start_x = (g->win_w - tex->width) / 2;
	start_y = (g->win_h - tex->height) / 2;
	for (int y = 0; y < tex->height; ++y)
	{
		for (int x = 0; x < tex->width; ++x)
		{
			color = get_tex_pixel(tex, x, y);
			put_pixel(&g->screen, start_x + x, start_y + y, color);
		}
	}
}

// se remplaza por el raycasting
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bit_pp / 8);
	*(unsigned int *)dst = color;
}

// se remplaza por el raycasting
unsigned int	get_tex_pixel(t_tex *tx, int x, int y)
{
	char	*dst;

	dst = tx->addr + y * tx->line_len + x * (tx->bit_pp / 8);
	return (*(unsigned int *)dst);
}
