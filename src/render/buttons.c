/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:17:41 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/11 17:17:45 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307)
		destroy_game(g);
	return (0);
}

int	close_window(t_game *g)
{
	destroy_game(g);
	return (0);
}
