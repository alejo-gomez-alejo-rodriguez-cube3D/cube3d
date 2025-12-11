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
int	init_mlx(t_game *game)
{
	game->img_mlx = mlx_init();
	if (!game->img_mlx)
		return (print_error("mlx_init falied"));
	game->win_w = 800;
	game->wind_h = 800;
	game->window = mlx_new_window(game->img_mlx, game->win_w, game->wind_h, "cub3D");
	if (!game->window)
		return (print_error("mlx_new_window falied"));
	game->screen.img_mlx = mlx_new_image(game->img_mlx, game->win_w, game->wind_h);
	if (!game->screen.img_mlx)
		return (print_error("mlx_new_image falied"));
	game->screen.addr = mlx_get_data_addr(game->screen.img_mlx, &game->screen.bit_pp, &game->screen.line_len, &game->screen.endian);
	return (0);
}

int	load_texture(t_game *g, t_tex *tex)
{
	tex->img_mlx = mlx_xpm_file_to_image(g->img_mlx, tex->path, &tex->width, &tex->height);
	if (!tex->img_mlx)
		return (print_error("Error loading texture"));
	tex->addr = mlx_get_data_addr(tex->addr, &tex->bit_pp, &tex->line_len, &tex->endian);
	return (0);
}
// check the images
int	load_all_textures(t_game *g)
{
	if (load_texture(g, &g->config.tex_east))
		return (1);
	if (load_texture(g, &g->config.tex_north))
		return (1);
	if (load_texture(g, &g->config.tex_south))
		return (1);
	if (load_texture(g, &g->config.tex_south))
		return (1);
	return (0);
}

void	set_hook(t_game *game)
{
	mlx_hook(game->window, 2, 1L<<0, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}

int	game_loop(t_game *g)
{
	if (g->runnig == 0)
		mlx_loop(g->img_mlx);
	mlx_put_image_to_window(g->img_mlx, g->window, g->screen.img_mlx, 0, 0);
	return (0);
}

// int    init_structs(t_game *g)
// {
// 	// if (img_init(g->img_mlx) || player_init(&g->player) || config_init(&g->config))
// 	// 	return (1);
// 	printf ("entra aqui\n");
// 	int i = 0;
// 	while (g->map.map[i] != NULL)
// 	{
// 		printf("%s\n", g->map.map[i]);
// 		i++;
// 	}
// 	return (0);
// }
