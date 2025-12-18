/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:29:32 by alejaro2          #+#    #+#             */
/*   Updated: 2025/12/18 18:29:34 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] != '\n')
		return (0);
	return (1);
}

static int	convert_rgb(char **rgb, int *dest)
{
	int	r;
	int	g;
	int	b;

	if (!is_numeric(rgb[0]) || !is_numeric(rgb[1]) || !is_numeric(rgb[2]))
		return (print_error("Color contains non-numeric characters"));
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_error("RGB color out of range (0-255)"));
	*dest = (r << 16) | (g << 8) | b;
	return (0);
}

static void	set_color_flag(t_game *game, char type)
{
	if (type == 'F')
		game->config.is_floor_set = 1;
	else
		game->config.is_ceil_set = 1;
}

int	parse_color(char *ptr, t_game *game, char type)
{
	char	**rgb;
	int		err;

	if ((type == 'F' && game->config.is_floor_set) || (type == 'C'
			&& game->config.is_ceil_set))
		return (print_error("Duplicate color defined"));
	ptr += 2;
	rgb = ft_split(ptr, ',');
	if (!rgb)
		return (print_error("Memory allocation failed"));
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_array(rgb);
		return (print_error("Invalid color format (3 values R,G,B required)"));
	}
	if (type == 'F')
		err = convert_rgb(rgb, &game->config.color_floor);
	else
		err = convert_rgb(rgb, &game->config.color_ceiling);
	if (err == 0)
		set_color_flag(game, type);
	free_array(rgb);
	return (err);
}
