/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:25 by alejandro         #+#    #+#             */
/*   Updated: 2025/11/29 17:54:35 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/render.h"

// static void	parser_provitional(char **args, t_data *data)
// {
// 	int	fd;
// 	int	len;
// 	int	line_len;
// 	char	*line;
// 	char	**map;

// 	len = 0;
// 	line_len = 0;
// 	fd = open(args[1], O_RDONLY);
// 	if (fd < 0)
// 		return ;
// 	line = get_next_line(fd);
// 	if (!line)
// 		return ;
// 	data->map = malloc(sizeof(char **) * 40);
// 	if (!data->map)
// 		return ;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		line_len = ft_strlen(line);
// 		data->map[len] == malloc(sizeof(char) * line_len + 1);
// 		if (!data->map[len])
// 			return ;
// 		data->map[len] = ft_strdup(line);
// 		data->map[len][line_len + 1] = '\0';
// 		len++;
// 		free(line);
// 	}
// 	close(fd);
// }
static int parser_provisional(char **args, t_map *data)
{
    int fd;
    char *line = NULL;
    char **map = NULL;
    size_t count = 0;

    if (!args || !args[1] || !data) return -1;
    fd = open(args[1], O_RDONLY);
    if (fd < 0) return -1;

    while ((line = get_next_line(fd)) != NULL)
    {
        /* quitar '\n' si existe */
        size_t l = ft_strlen(line);
        if (l > 0 && line[l - 1] == '\n')
            line[l - 1] = '\0';

        /* realloc para crecer el array de punteros */
        char **tmp = realloc(map, sizeof *map * (count + 2)); /* +1 para la nueva, +1 para NULL */
        if (!tmp) { free(line); /* liberar map parcial */ /* liberar map[i] */ close(fd); return -1; }
        map = tmp;

        map[count] = ft_strdup(line);
        if (!map[count]) { free(line); /* liberar map parcial */ close(fd); return -1; }

        count++;
        map[count] = NULL; /* mantener siempre NULL-terminated */
        free(line);
    }

    close(fd);

    if (!map) {
        /* fichero vacío -> crear array con solo NULL */
        map = malloc(sizeof *map);
        if (!map) return -1;
        map[0] = NULL;
    }

    data->map = map;
    return 0;
}

int main(int ac, char **args)
{
	t_game	g;

	if (ac != 2)
		return (1);
	if (parser_provisional(args, &g.map))
		return (1);
	init_struct(&g);
	// int i = 0;
	// while (g.map.map[i] != NULL)
	// {
	// 	printf("%s\n", g.map.map[i]);
	// 	i++;
	// }
	return (0);
}
