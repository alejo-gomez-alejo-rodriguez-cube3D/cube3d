/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:49:04 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/14 17:49:07 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	set_hook(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
