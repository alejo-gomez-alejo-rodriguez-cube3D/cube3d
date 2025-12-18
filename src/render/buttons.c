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

int key_press(int keycode, t_game *g)
{
    if (keycode == KEY_W)
        move_forward(g);
    else if (keycode == KEY_S)
        move_backward(g);
    else if (keycode == KEY_A)
        rotate_left(g);
    else if (keycode == KEY_D)
        rotate_right(g);
    else if (keycode == KEY_ESC)
		destroy_game(g);
    return (0);
}

int	close_window(t_game *g)
{
	destroy_game(g);
	return (0);
}
