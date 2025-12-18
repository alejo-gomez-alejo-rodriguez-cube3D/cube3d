/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:29:13 by alejaro2          #+#    #+#             */
/*   Updated: 2025/12/18 18:29:15 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_config(char *ptr, t_game *game)
{
	if (ft_strncmp(ptr, "NO ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_north, "NO"));
	else if (ft_strncmp(ptr, "SO ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_south, "SO"));
	else if (ft_strncmp(ptr, "WE ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_west, "WE"));
	else if (ft_strncmp(ptr, "EA ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_east, "EA"));
	else if (ft_strncmp(ptr, "DO ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_door, "DO"));
	else if (ft_strncmp(ptr, "SP ", 3) == 0)
		return (parse_texture(ptr, &game->config.tex_sprite, "SP"));
	else if (ft_strncmp(ptr, "F ", 2) == 0)
		return (parse_color(ptr, game, 'F'));
	else if (ft_strncmp(ptr, "C ", 2) == 0)
		return (parse_color(ptr, game, 'C'));
	return (-1);
}

static int	process_map_content(char *line, t_game *game)
{
	if (game->map.has_ended)
	{
		get_next_line(-1);
		return (print_error("Empty line inside map"));
	}
	return (parse_map_line(line, game));
}

static int	parse_line(char *line, t_game *game)
{
	char	*ptr;
	int		status;

	if (is_empty_line(line))
	{
		if (game->map.rows > 0)
			game->map.has_ended = 1;
		return (0);
	}
	ptr = skip_spaces(line);
	status = parse_config(ptr, game);
	if (status == 0 || status == 1)
		return (status);
	if (*ptr == '1' || *ptr == '0')
		return (process_map_content(line, game));
	return (print_error("Unknown line"));
}

int	parse_file(char *file_path, t_game *game)
{
	int		fd;
	char	*line;
	int		error;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (print_error("Could not open file"));
	error = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		error = parse_line(line, game);
		free(line);
		if (error != 0)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	return (error);
}
