/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:43:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/09 15:10:20 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	init_visited(t_data *data)
{
	int	i;

	i = 0;
	data->visited = calloc(data->rows, sizeof(char*));
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

static void	init_map(char *mapfile, t_data *data)
{
	data->rows = check_mapfile(data, mapfile);
	fill_map(mapfile, data);
	check_cols(data);
	check_walls(data);
	check_chars(data);
	init_visited(data);
	check_access(data);
}

static	void	init_mlx(t_data *data)
{	
	data->tile_size = 50;
	data->height = data->rows * data->tile_size;
	data->width = data->cols * data->tile_size;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data->mlx = mlx_init(data->width, data->height, "VOID", true);
	if (!data->mlx)
		quit_data_perror(data, "MLX42 failed");

/*
	data->img_player = convert_png(data, "assets/p.png");
	data->img_wall = convert_png(data, "assets/1.png");
	data->img_token = convert_png(data, "assets/c.png");
	data->img_exit = convert_png(data, "assets/e.png");
	data->img_empty = convert_png(data, "assets/0.png");
*/
	data->img_player = convert_png(data, "assets/player.png");
	data->img_wall = convert_png(data, "assets/black.png");
	data->img_token = convert_png(data, "assets/token.png");
	data->img_exit = convert_png(data, "assets/exit.png");
	data->img_empty = convert_png(data, "assets/white.png");
}

void	init_data(char *mapfile, t_data *data)
{
	init_map(mapfile, data);
	init_mlx(data);
	data->x = data->start_point.x;
	data->y = data->start_point.y;
	data->moves = 0;
}