/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:30:11 by alejagom          #+#    #+#             */
/*   Updated: 2025/12/12 15:45:53 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_constants(t_game *g)
{
	g->win_w = 800;
	g->win_h = 600;
	g->move_speed = MOVE_SPEED_BASE;
	g->rot_speed = ROT_SPEED_BASE;
	g->runnig = 1;
	g->input.forward = 0;
	g->input.backward = 0;
	g->input.rotate_left = 0;
	g->input.rotate_right = 0;
	g->config.is_floor_set = 0;
	g->config.is_ceil_set = 0;
}

int	init_mlx(t_game *game)
{
	game->img_mlx = mlx_init();
	if (!game->img_mlx)
		return (print_error("mlx_init falied"));
	game->window = mlx_new_window(game->img_mlx, game->win_w, game->win_h,
			"cub3D");
	if (!game->window)
		return (print_error("mlx_new_window falied"));
	game->screen.img_mlx = mlx_new_image(game->img_mlx, game->win_w,
			game->win_h);
	if (!game->screen.img_mlx)
		return (print_error("mlx_new_image falied"));
	game->screen.addr = mlx_get_data_addr(game->screen.img_mlx,
			&game->screen.bit_pp, &game->screen.line_len, &game->screen.endian);
	game->screen.width = game->win_w;
	game->screen.height = game->win_h;
	return (0);
}

int	init_game(t_game *g)
{
	printf("gonorrea \n");
	init_constants(g);
	if (init_mlx(g))
		return (1);
	g->mlx_initialized = 1;
	if (load_all_textures(g))
		return (1);
	return (0);
}

int	game_loop(t_game *g)
{
	get_delta_time(g);
	if (g->runnig == 0)
		return (0);
	handle_input(g);
	raycast_scene(g);
	mlx_put_image_to_window(g->img_mlx, g->window, g->screen.img_mlx, 0, 0);
	return (0);
}
