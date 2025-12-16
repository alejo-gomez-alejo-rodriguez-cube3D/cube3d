/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:39:48 by alejandro         #+#    #+#             */
/*   Updated: 2025/12/12 17:39:50 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bit_pp / 8);
	*(unsigned int *)dst = color;
}

unsigned int	get_tex_pixel(t_tex *tx, int x, int y)
{
	char	*dst;

	dst = tx->addr + y * tx->line_len + x * (tx->bit_pp / 8);
	return (*(unsigned int *)dst);
}
