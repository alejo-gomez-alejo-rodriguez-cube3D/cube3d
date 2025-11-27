/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:25 by alejandro         #+#    #+#             */
/*   Updated: 2025/11/27 17:16:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parser_provitional(char **args, t_data *data)
{
	int	fd;
	int	len;

	len = 0;
	fd = open(args[1], O_RDONLY);
	if (!fd)
		return ;
	while (args[1][len])
	{
		data->map[len] = get_next_line(fd);
		len++; 
	}
	data->map[len + 1] = '\0';
	if (!data->map)
		return ;
}

int main(int ac, char **args)
{
	t_data	data;

	if (ac != 2)
		return (1);
	parser_provitional(args, &data);
	return (0);
}
