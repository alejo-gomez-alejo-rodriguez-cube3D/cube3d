#include "../../includes/cub3d.h"

int	parse_file(char *file_path, t_game *game)
{
	int		fd;
	char	*line;

    game = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nNo se pudo abrir el archivo\n"), 1);
	
	line = get_next_line(fd);
	while (line != NULL)
	{
		// Aquí analizaremos cada línea
		// if (parse_line(line, game) != 0)
		// {
		//     free(line);
		//     close(fd);
		//     return (1);
		// }
		
		// Temporalmente solo las imprimimos para probar
		printf("Leyendo: %s", line);
		
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}