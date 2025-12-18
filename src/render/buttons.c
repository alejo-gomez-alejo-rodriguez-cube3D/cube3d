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

void move_backward(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x - g->player.dir_x * g->move_speed;
    new_y = g->player.y - g->player.dir_y * g->move_speed;

    if (g->map.map[(int)g->player.y][(int)new_x] != '1')
        g->player.x = new_x;
    if (g->map.map[(int)new_y][(int)g->player.x] != '1')
        g->player.y = new_y;
}

void move_forward(t_game *g)
{
    double new_x;
    double new_y;

    new_x = g->player.x + g->player.dir_x * g->move_speed;
    new_y = g->player.y + g->player.dir_y * g->move_speed;

    if (g->map.map[(int)g->player.y][(int)new_x] != '1')
        g->player.x = new_x;
    if (g->map.map[(int)new_y][(int)g->player.x] != '1')
        g->player.y = new_y;
}

void rotate_left(t_game *g)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = g->player.dir_x;
    g->player.dir_x = g->player.dir_x * cos(g->rot_speed)
                    - g->player.dir_y * sin(g->rot_speed);
    g->player.dir_y = old_dir_x * sin(g->rot_speed)
                    + g->player.dir_y * cos(g->rot_speed);

    old_plane_x = g->player.plane_x;
    g->player.plane_x = g->player.plane_x * cos(g->rot_speed)
                      - g->player.plane_y * sin(g->rot_speed);
    g->player.plane_y = old_plane_x * sin(g->rot_speed)
                      + g->player.plane_y * cos(g->rot_speed);
}

void rotate_right(t_game *g)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = g->player.dir_x;
    g->player.dir_x = g->player.dir_x * cos(-g->rot_speed)
                    - g->player.dir_y * sin(-g->rot_speed);
    g->player.dir_y = old_dir_x * sin(-g->rot_speed)
                    + g->player.dir_y * cos(-g->rot_speed);

    old_plane_x = g->player.plane_x;
    g->player.plane_x = g->player.plane_x * cos(-g->rot_speed)
                      - g->player.plane_y * sin(-g->rot_speed);
    g->player.plane_y = old_plane_x * sin(-g->rot_speed)
                      + g->player.plane_y * cos(-g->rot_speed);
}

void handle_input(t_game *g)
{
    if (g->input.forward)
        move_forward(g);
    if (g->input.backward)
        move_backward(g);
    if (g->input.rotate_left)
        rotate_left(g);
    if (g->input.rotate_right)
        rotate_right(g);
}

int key_release(int keycode, t_game *g)
{
    if (keycode == KEY_W)
        g->input.forward = 0;
    else if (keycode == KEY_S)
        g->input.backward = 0;
    else if (keycode == KEY_A)
        g->input.rotate_left = 0;
    else if (keycode == KEY_D)
        g->input.rotate_right = 0;
    return (0);
}

int key_press(int keycode, t_game *g)
{
    if (keycode == KEY_W)
		g->input.forward = 1;
    else if (keycode == KEY_S)
		g->input.backward = 1;
    else if (keycode == KEY_A)
		g->input.rotate_left = 1;
    else if (keycode == KEY_D)
		g->input.rotate_right = 1;
    else if (keycode == KEY_ESC)
		destroy_game(g);
    return (0);
}

int	close_window(t_game *g)
{
	destroy_game(g);
	return (0);
}
