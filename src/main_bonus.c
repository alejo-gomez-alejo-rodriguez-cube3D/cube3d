/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:36:53 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/05 00:03:26 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/bonus.h"

int	check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	game_loop_bonus(t_game *game)
{
	game_loop(game);
	draw_minimap(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D_bonus <map.cub>"));
	if (check_extension(argv[1]))
		return (print_error("File must have .cub extension"));
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(argv[1], &game) != 0)
	{
		free_game(&game);
		return (1);
	}
	if (validate_map(&game) != 0)
	{
		free_game(&game);
		return (1);
	}
	init_player(&game.player);
	if (init_game(&game))
		return (1);
	set_hook(&game);
	game.runnig = 1;
	game.last_time = get_time_ms();
	mlx_loop_hook(game.img_mlx, game_loop_bonus, &game);
	mlx_loop(game.img_mlx);
	// free_game(&game);
	return (0);
}
