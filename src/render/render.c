/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:30:11 by alejagom          #+#    #+#             */
/*   Updated: 2025/11/29 17:58:24 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void    init_structs(t_game *g)
{
	img_init(g->img_mlx);
	player_init(g->player);
	// int i = 0;
	// while (g->map.map[i] != NULL)
	// {
	// 	printf("%s\n", g->map.map[i]);
	// 	i++;
	// }
}
