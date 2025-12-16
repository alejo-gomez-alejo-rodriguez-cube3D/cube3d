#include "../includes/cub3d.h"

// poner despues del mergeo.
// void init_player(t_player *p)
// {
//     if (!p->dir_char)
//         return;

//     if (*p->dir_char == 'N')
//     {
//         p->dir_x = 0;
//         p->dir_y = -1;
//         p->plane_x = 0.66;
//         p->plane_y = 0;
//     }
//     else if (*p->dir_char == 'S')
//     {
//         p->dir_x = 0;
//         p->dir_y = 1;
//         p->plane_x = -0.66;
//         p->plane_y = 0;
//     }
//     else if (*p->dir_char == 'E')
//     {
//         p->dir_x = 1;
//         p->dir_y = 0;
//         p->plane_x = 0;
//         p->plane_y = 0.66;
//     }
//     else if (*p->dir_char == 'W')
//     {
//         p->dir_x = -1;
//         p->dir_y = 0;
//         p->plane_x = 0;
//         p->plane_y = -0.66;
//     }
// }

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
	if (validate_map(&game) != 0)
		return (1);
	
	//init_player despues del mergeo.
	if (init_game(&game))
		return (1);
	set_hook(&game);
	game.runnig = 1;
	mlx_loop_hook(game.img_mlx, game_loop, &game);
	mlx_loop(game.img_mlx);
	return (0);
}
