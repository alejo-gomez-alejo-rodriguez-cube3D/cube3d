/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:45:54 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/14 17:45:55 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	load_texture(t_game *g, t_tex *tex)
{
	if (!tex->path)
		return (print_error("Texture path NULL"), 1);
	tex->img_mlx = mlx_xpm_file_to_image(g->img_mlx, tex->path, &tex->width,
			&tex->height);
	if (!tex->img_mlx)
		return (print_error("Error loading texture"));
	tex->addr = mlx_get_data_addr(tex->img_mlx, &tex->bit_pp, &tex->line_len,
			&tex->endian);
	return (0);
}

int	load_all_textures(t_game *g)
{
	if (load_texture(g, &g->config.tex_east))
		return (1);
	if (load_texture(g, &g->config.tex_north))
		return (1);
	if (load_texture(g, &g->config.tex_south))
		return (1);
	if (load_texture(g, &g->config.tex_west))
		return (1);
	if (g->bonus_enabled)
	{
		if (load_texture(g, &g->config.tex_door))
			return (1);
	}
	return (0);
}
