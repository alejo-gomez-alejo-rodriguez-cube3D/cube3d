/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:36:53 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 17:36:56 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D <map.cub>"));
	if (check_extension(argv[1]))
		return (print_error("File must have .cub extension"));
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(argv[1], &game) != 0)
		return (free_game(&game), 1);
	if (validate_map(&game) != 0)
		return (free_game(&game), 1);
	init_player(&game.player);
	if (init_game(&game))
		return (1);
	set_hook(&game);
	game.runnig = 1;
	game.last_time = get_time_ms();
	mlx_loop_hook(game.img_mlx, game_loop, &game);
	mlx_loop(game.img_mlx);
	return (0);
}
