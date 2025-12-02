/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:25 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/02 14:29:22 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/render.h"

int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (1);
}

int	check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error("Uso correcto: ./cub3D <mapa.cub>"));
	if (check_extension(av[1]))
		return (print_error("El archivo debe tener extensión .cub"));
	
	ft_memset(&game, 0, sizeof(t_game));
	
	if (parse_file(av[1], &game) != 0)
		return (1);

	printf("Mapa leido OK. Textura Norte: %s\n", game.config.tex_north.addr);

	return (0);
}
