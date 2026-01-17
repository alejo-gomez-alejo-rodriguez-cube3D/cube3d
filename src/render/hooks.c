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

void	handle_input(t_game *g)
{
	if (g->input.forward)
		move_forward(g);
	if (g->input.backward)
		move_backward(g);
	if (g->input.strafe_right)
		strafe_right(g);
	if (g->input.strafe_left)
		strafe_left(g);
	if (g->input.rotate_left)
		rotate_by_angle(g, g->rot_speed * g->delta_time);
	if (g->input.rotate_right)
		rotate_by_angle(g, -g->rot_speed * g->delta_time);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		g->input.forward = 0;
	else if (keycode == KEY_S)
		g->input.backward = 0;
	else if (keycode == KEY_D)
		g->input.strafe_right = 0;
	else if (keycode == KEY_A)
		g->input.strafe_left = 0;
	else if (keycode == LEFT)
		g->input.rotate_left = 0;
	else if (keycode == RIGHT)
		g->input.rotate_right = 0;
	else if (keycode == KEY_E)
		g->press_e = 0;
	return (0);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		g->input.forward = 1;
	else if (keycode == KEY_S)
		g->input.backward = 1;
	else if (keycode == KEY_D)
		g->input.strafe_right = 1;
	else if (keycode == KEY_A)
		g->input.strafe_left = 1;
	else if (keycode == LEFT)
		g->input.rotate_left = 1;
	else if (keycode == RIGHT)
		g->input.rotate_right = 1;
	else if (keycode == KEY_E && g->press_e == 0)
	{
		toggle_door(g);
		g->press_e = 1;
	}
	else if (keycode == KEY_ESC)
		free_game(g);
	return (0);
}

int	close_window(t_game *g)
{
	free_game(g);
	return (0);
}

void	set_hook(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}
