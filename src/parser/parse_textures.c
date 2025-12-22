/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:28:00 by alejaro2          #+#    #+#             */
/*   Updated: 2025/12/18 18:28:02 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <fcntl.h>

static int	check_file_exists(char *path)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error\nTexture must be .xpm: %s\n", path);
		return (1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCannot open texture: %s\n", path);
		return (1);
	}
	close(fd);
	return (0);
}

static int	check_duplicate(char *path, char *type)
{
	if (path != NULL)
	{
		printf("Error\nDuplicate texture found: %s\n", type);
		return (1);
	}
	return (0);
}

int	parse_texture(char *line, t_tex *tex, char *type)
{
	char	*ptr;

	if (check_duplicate(tex->path, type))
		return (1);
	ptr = line + 2;
	tex->path = ft_strtrim(ptr, " \n\t");
	if (!tex->path)
		return (print_error("Memory allocation failed for texture path"));
	if (ft_strlen(tex->path) == 0)
	{
		free(tex->path);
		tex->path = NULL;
		return (print_error("Texture path is empty"));
	}
	if (check_file_exists(tex->path) != 0)
	{
		free(tex->path);
		tex->path = NULL;
		return (1);
	}
	return (0);
}
