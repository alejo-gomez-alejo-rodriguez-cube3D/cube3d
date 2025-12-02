/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:30:11 by alejagom          #+#    #+#             */
/*   Updated: 2025/12/01 18:27:29 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// static int	img_init(t_img *mlx)
// {
// 	mlx->addr = NULL;
// 	mlx->bit_pp = 0;
// 	mlx->endian = 0;
// 	mlx->height = 0;
// 	mlx->img_mlx = NULL;
// 	mlx->line_len = 0;
// 	mlx->width = 0;
// 	return (0);
// }

// static int	player_init(t_player *player)
// {
// 	player->dir_char = NULL;
// 	player->dir_x = 0;
// 	player->dir_y = 0;
// 	player->plane_x = 0;
// 	player->plane_y = 0;
// 	player->x = 0;
// 	player->y = 0;
// 	return (0);
// }

// static int	init_tex(t_tex *tex)
// {
// 	tex->addr = NULL;
// 	tex->bit_pp = 0;
// 	tex->endian = 0;
// 	tex->height = 0;
// 	tex->img_mlx = NULL;
// 	tex->line_len = 0;
// 	tex->width = 0;
// 	return (0);
// }

// static int	config_init(t_config *config)
// {
// 	config->color_ceiling = 0;
// 	config->color_floor = 0;
// 	if (init_tex(&config->tex_east) || init_tex(&config->tex_north)
// 		|| init_tex(&config->tex_south) || init_tex(&config->tex_west))
// 		return (1);
// 	return (0);
// }

int    init_structs(t_game *g)
{
	// if (img_init(g->img_mlx) || player_init(&g->player) || config_init(&g->config))
	// 	return (1);
	printf ("entra aqui\n");
	int i = 0;
	while (g->map.map[i] != NULL)
	{
		printf("%s\n", g->map.map[i]);
		i++;
	}
	return (0);
}
