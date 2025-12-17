/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:15 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/13 18:12:18 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	destroy_game(t_game *g)
{
	if (g->screen.img_mlx)
		mlx_destroy_image(g->img_mlx, g->screen.img_mlx);
	if (g->config.tex_north.img_mlx)
		mlx_destroy_image(g->img_mlx, g->config.tex_north.img_mlx);
	if (g->config.tex_south.img_mlx)
		mlx_destroy_image(g->img_mlx, g->config.tex_south.img_mlx);
	if (g->config.tex_east.img_mlx)
		mlx_destroy_image(g->img_mlx, g->config.tex_east.img_mlx);
	if (g->config.tex_west.img_mlx)
		mlx_destroy_image(g->img_mlx, g->config.tex_west.img_mlx);
	if (g->window)
		mlx_destroy_window(g->img_mlx, g->window);
	printf("Exit\n");
	exit(0);
	return (0);
}
