/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:15 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/08 15:41:14 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	free_game(t_game *game)
{
	free_textures(game);
	free_map_array(game);
	destroy_game(game);
	// if (game->mlx)
	// {
	// 	mlx_destroy_display(game->mlx); // Solo en Linux
	// 	free(game->mlx);
	// }
	return (0);
}

void	free_map_array(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.map == NULL)
		return ;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

void	free_textures(t_game *game)
{
	if (game->config.tex_north.path)
		free(game->config.tex_north.path);
	if (game->config.tex_south.path)
		free(game->config.tex_south.path);
	if (game->config.tex_west.path)
		free(game->config.tex_west.path);
	if (game->config.tex_east.path)
		free(game->config.tex_east.path);
	if (game->config.tex_door.path)
		free(game->config.tex_door.path);
	if (game->config.tex_sprite.path)
		free(game->config.tex_sprite.path);
}

void	destroy_game(t_game *g)
{
	if (g->mlx_initialized)
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
		exit (0);
	}
}
