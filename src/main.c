#include "../includes/cub3d.h"
#include "../includes/render.h"


int	check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D <map.cub>"));
	if (check_extension(argv[1]))
		return (print_error("File must have .cub extension"));
	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(argv[1], &game) != 0)
		return (1);
	// if(init_structs(&game)) //borrar
	// 	return (1);
	if (init_mlx(&game))
		return (1);
	if (load_all_textures(&game))
		return (1);
	set_hook(&game);
	game.runnig = 1;
	mlx_loop_hook(game.img_mlx, game_loop, &game);
	mlx_loop(game.img_mlx);
	return (0);
}
