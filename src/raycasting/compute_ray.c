/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:44:07 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/16 18:44:08 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void compute_perp_dist(t_ray *r)
{
    if (r->side == 0)
        r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
    else
        r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

void compute_line_height(t_game *g, t_ray *r)
{
    r->line_height = (int)(g->win_h / r->perp_wall_dist);
}

void compute_draw_limits(t_game *g, t_ray *r)
{
    r->draw_start = -r->line_height / 2 + g->win_h / 2;
    if (r->draw_start < 0)
        r->draw_start = 0;

    r->draw_end = r->line_height / 2 + g->win_h / 2;
    if (r->draw_end >= g->win_h)
        r->draw_end = g->win_h - 1;
}

void compute_wall(t_game *g, t_ray *r)
{
    compute_perp_dist(r);
    compute_line_height(g, r);
    compute_draw_limits(g, r);
}
