
#include "../../includes/cub3d.h"
#include <stdlib.h>

static void	free_map_array(t_game *game)
{
	int	i;

	if (game->map.map == NULL)
		return ;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

static void	free_textures(t_game *game)
{
	if (game->config.tex_north.path)
		free(game->config.tex_north.path);
	if (game->config.tex_south.path)
		free(game->config.tex_south.path);
	if (game->config.tex_west.path)
		free(game->config.tex_west.path);
	if (game->config.tex_east.path)
		free(game->config.tex_east.path);
	if (game->config.tex_door.path)
		free(game->config.tex_door.path);
	if (game->config.tex_sprite.path)
		free(game->config.tex_sprite.path);
}

int	free_game(t_game *game)
{
	free_textures(game);
	free_map_array(game);

	// Más adelante, cuando añadamos gráficos, aquí liberar
	// la ventana y la imagen (mlx_destroy_window, etc.)
	/*
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx); // Solo en Linux
		free(game->mlx);
	}
	*/
	return (0);
}

int	exit_error(t_game *game, char *msg)
{
	print_error(msg);
	free_game(game);
	exit(1);
	return (1);
}