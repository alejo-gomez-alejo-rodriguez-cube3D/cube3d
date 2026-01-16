/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:30:28 by alejandro         #+#    #+#             */
/*   Updated: 2026/01/16 21:21:10 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus.h"

void	save_door(t_game *g, int x, int y)
{
	g->doors[g->count_doors].x = x;
	g->doors[g->count_doors].y = y;
	g->doors[g->count_doors].open = 0;
	g->count_doors++;
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

int	is_door_close(t_game *g, int x, int y)
{
	int	i;

	i = find_door(g, x, y);
	if (i != -1)
		return (!g->doors[i].open);
	return (0);
}

void	toggle_door(t_game *g)
{
	int	x;
	int	y;
	int	i;

	x = (int)(g->player.x + g->player.dir_x);
	y = (int)(g->player.y + g->player.dir_y);
	if (g->map.map[y][x] == 'D')
	{
		i = find_door(g, x, y);
		if (i != -1)
			g->doors[i].open = !g->doors[i].open;
	}
}

void	free_doors(t_game *game)
{
	if (game->doors)
	{
		free(game->doors);
		game->doors = NULL;
	}
}
