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

// perspectiva del jugador
void	init_player(t_player *p)
{
	int					i;
	const t_dir_init	dirs[4] = {{'N', 0.0, -1.0, 0.50, 0.0},
	{'S', 0.0, 1.0, -0.50, 0.0}, {'E', 1.0, 0.0, 0.0, 0.50},
	{'W', -1.0, 0.0, 0.0, -0.50}};

	i = 0;
	while (i < 4)
	{
		if (p->dir_char == dirs[i].dir)
		{
			p->dir_x = dirs[i].dir_x;
			p->dir_y = dirs[i].dir_y;
			p->plane_x = dirs[i].plane_x;
			p->plane_y = dirs[i].plane_y;
			return ;
		}
		i++;
	}
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bit_pp / 8);
	*(unsigned int *)dst = color;
}

unsigned int	get_tex_pixel(t_tex *tx, int x, int y)
{
	char	*dst;

	dst = tx->addr + y * tx->line_len + x * (tx->bit_pp / 8);
	return (*(unsigned int *)dst);
}
