/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:58:05 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/27 17:58:08 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	get_delta_time(t_game *g)
{
	double	time;

	time = get_time_ms();
	g->delta_time = time - g->last_time;
	g->last_time = time;
	if (g->delta_time > 0.05)
		g->delta_time = 0.05;
}

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

int	exit_error(t_game *game, char *msg)
{
	print_error(msg);
	free_game(game);
	exit(1);
	return (1);
}
