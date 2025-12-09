/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:25 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/09 14:45:38 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/render.h"

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
		return (1);
	printf("Map loaded successfully: %s\n", game.config.tex_north.addr);
	return (0);
}
