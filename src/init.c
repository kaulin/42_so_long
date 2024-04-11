/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:43:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 10:16:17 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Opens the map file, callocs for the map array, and stores each row from the 
file into the array using ft_get_next_line.
*/
static void	fill_map(char *mapfile, t_data *data)
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
		if (!data->map[i])
		{
			close(data->fd);
			quit_data_perror(data, "Error reading file");
		}
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = 0;
		i++;
	}
	close(data->fd);
}

/*
Initializes the visited array for flood fill using calloc.
*/
static void	init_visited(t_data *data)
{
	int	i;

	i = 0;
	data->visited = calloc(data->rows, sizeof(char *));
	if (!data->visited)
		quit_data_perror(data, "Memory allocation error");
	while (i < data->rows)
	{
		data->visited[i] = calloc(data->cols, sizeof(char));
		if (!data->visited[i])
			quit_data_perror(data, "Memory allocation error");
		i++;
	}
}

/*
Checks the mapfile, fills the map and performs checks to ensure map is valid.
*/
static void	init_map(char *mapfile, t_data *data)
{
	data->rows = check_mapfile(data, mapfile);
	fill_map(mapfile, data);
	check_cols(data);
	check_walls(data);
	check_chars(data);
	init_visited(data);
	check_access(data);
	if (data->cols * data->rows > 16000)
		quit_data_error(data, "The map is valid, but I am saving the poor old \
Intel Core i5 running this thing from crunching over 16000 tiles :)");
}

/*
Initializes MLX and stores the required images.
*/
static	void	init_mlx(t_data *data)
{
	data->tile_size = 21;
	data->height = data->rows * data->tile_size;
	data->width = data->cols * data->tile_size;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data->mlx = mlx_init(data->width, data->height, "NOT QUITE VOID", true);
	if (!data->mlx)
		quit_data_perror(data, "MLX42 failed");
	data->img_player = convert_png(data, "assets/21player.png");
	data->img_wall = convert_png(data, "assets/21black.png");
	data->img_token = convert_png(data, "assets/21token.png");
	data->img_exit = convert_png(data, "assets/21exit.png");
	data->img_empty = convert_png(data, "assets/21white.png");
}

/*
Initializes the data struct and in the end sets the current player location to 
the starting location.
*/
void	init_data(char *mapfile, t_data *data)
{
	data->map = NULL;
	data->visited = NULL;
	data->mlx = NULL;
	data->img_player = NULL;
	data->img_wall = NULL;
	data->img_token = NULL;
	data->img_exit = NULL;
	data->img_empty = NULL;
	init_map(mapfile, data);
	init_mlx(data);
	data->x = data->start_point.x;
	data->y = data->start_point.y;
	data->moves = 0;
}
