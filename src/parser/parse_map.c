#include "../../includes/cub3d.h"

static void	copy_map_pointers(char **src, char **dest, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dest[i] = src[i];
		i++;
	}
}

static int	add_line_to_map(t_game *game, char *line)
{
	char	**new_map;
	int		count;

	count = game->map.rows;
	new_map = malloc(sizeof(char *) * (count + 2));
	if (!new_map)
		return (print_error("Memory allocation failed for map resizing"));
	if (game->map.map)
	{
		copy_map_pointers(game->map.map, new_map, count);
		free(game->map.map);
	}
	new_map[count] = ft_strtrim(line, "\n");
	if (!new_map[count])
	{
		free(new_map);
		return (print_error("Memory allocation failed for map line"));
	}
	new_map[count + 1] = NULL;
	game->map.map = new_map;
	game->map.rows++;
	return (0);
}

static int	check_textures_loaded(t_game *game)
{
	if (!game->config.tex_north.path || !game->config.tex_south.path
		|| !game->config.tex_west.path || !game->config.tex_east.path
		|| !game->config.is_floor_set || !game->config.is_ceil_set)
		return (0);
	return (1);
}

int	parse_map_line(char *line, t_game *game)
{
	if (!check_textures_loaded(game))
		return (print_error("Map content found before configuration"));
	return (add_line_to_map(game, line));
}
