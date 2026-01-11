/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:30:28 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 19:30:29 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus.h"

int	is_door_close(t_game *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < g->count_doors)
	{
		if (g->doors[i].x == x && g->doors[i].y == y)
			return (!g->doors[i].open);
		i++;
	}
	return (0);
}

void	free_doors(t_game *game)
{
	if (game->doors)
	{
		free(game->doors);
		game->doors = NULL;
	}
}

void	door_toggle_state(t_game *g, int door_index)
{
	if (door_index < 0)
		return ;
	g->doors[door_index].open = !g->doors[door_index].open;
}

int	find_door(t_game *g, int x, int y)
{
	int	i;

	i = 0;
	while (i < g->count_doors)
	{
		if (g->doors[i].x == x && g->doors[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

void	toggle_door(t_game *g)
{
	int	x;
	int	y;
	int	i;

	x = (int)(g->player.x + g->player.dir_x);
	y = (int)(g->player.y + g->player.dir_y);
	if (g->map.map[y][x] != 'D')
		return ;
	i = find_door(g, x, y);
	if (i < 0)
		return ;
	door_toggle_state(g, i);
}

void	save_door(t_game *g, int x, int y)
{
	g->doors[g->count_doors].x = x;
	g->doors[g->count_doors].y = y;
	g->doors[g->count_doors].open = 0;
	g->count_doors++;
}
