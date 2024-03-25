/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:43:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/25 16:28:16 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void fill_map(char *mapfile, t_data *data)
{
	int	i;

	i = 0;
	data->fd = open(mapfile, O_RDONLY);
	if (data->fd == -1)
		quit_perror("Error reading map file");
	data->map = ft_calloc(data->rows, sizeof(char *));
	if (!data->map)
	{
		close(data->fd);
		quit_perror("Memory allocation error");
	}
	while (i < data->rows)
	{
		data->map[i] = ft_get_next_line(data->fd);
		if (!data->map[i]){
			close(data->fd);
			quit_data_perror(data, "Error reading file");
		}
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = 0;
		i++;
	}
	close(data->fd);
}

static void	init_map(char *mapfile, t_data *data)
{
	data->rows = check_mapfile(data, mapfile);
	fill_map(mapfile, data);
	print_map(data);
	check_cols(data);
	check_walls(data);
	check_chars(data);
	check_access(data);
}

void	init_data(char *mapfile, t_data *data)
{
	init_map(mapfile, data);
	return ;
}