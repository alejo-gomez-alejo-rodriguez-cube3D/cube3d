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

#include "./bonus.h"

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

int	count_doors(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_doors(t_game *game)
{
	int	count;

	count = count_doors(game->map.map);
	game->count_doors = count;
	if (count == 0)
	{
		game->count_doors = 0;
		return ;
	}
	game->doors = malloc(sizeof(t_door) * count);
	if (!game->doors)
	{
		print_error("Malloc falied for doors");
		exit (1);
	}
	game->count_doors = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D_bonus <map.cub>"));
	if (check_extension(argv[1]))
		return (print_error("File must have .cub extension"));
	ft_memset(&game, 0, sizeof(t_game));
	game.bonus_enabled = 1;
	if (parse_file(argv[1], &game) != 0)
		return (free_game(&game), 1);
	init_doors(&game);
	if (validate_map(&game) != 0)
		return (free_game(&game), 1);
	init_player(&game.player);
	if (init_game_bonus(&game))
		return (1);
	set_hook_bonus(&game);
	game.runnig = 1;
	game.last_time = get_time_ms();
	mlx_loop_hook(game.img_mlx, game_loop_bonus, &game);
	mlx_loop(game.img_mlx);
	return (0);
}
