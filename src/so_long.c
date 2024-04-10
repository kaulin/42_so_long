/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/10 17:58:18 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_data *data, char c, int i, int j)
{
	int		x;
	int		y;

	x = j * data->tile_size;
	y = i * data->tile_size;
	if (c == '1' \
		&& mlx_image_to_window(data->mlx, data->img_wall, x, y) < 0)
		quit_data_perror(data, "MLX42 failed");
	else if (c == '0' \
		&& mlx_image_to_window(data->mlx, data->img_empty, x, y) < 0)
		quit_data_perror(data, "MLX42 failed");
	else if (c == 'E' \
		&& mlx_image_to_window(data->mlx, data->img_exit, x, y) < 0)
		quit_data_perror(data, "MLX42 failed");
	else if (c == 'P' \
		&& mlx_image_to_window(data->mlx, data->img_player, x, y) < 0)
		quit_data_perror(data, "MLX42 failed");
	else if (c == 'C' \
		&& mlx_image_to_window(data->mlx, data->img_token, x, y) < 0)
		quit_data_perror(data, "MLX42 failed");
}

static void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			draw_tile(data, data->map[i][j], i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	move_to(t_data *data, int x, int y)
{
	char	this;

	this = data->map[y][x];
	if (this == '1')
		return ;
	data->moves++;
	ft_printf("Moves: %d\n", data->moves);
	if (data->map[data->y][data->x] != 'E')
		data->map[data->y][data->x] = '0';
	draw_tile(data, data->map[data->y][data->x], data->y, data->x);
	data->x = x;
	data->y = y;
	draw_tile(data, 'P', y, x);
	if (this == 'C')
		data->tokens -= 1;
	else if (this == 'E' && !data->tokens)
		quit_success(data, "This is a victory!");
}

static void	so_long(char *mapfile)
{
	t_data	data;

	init_data(mapfile, &data);
	draw_map(&data);
	mlx_loop_hook(data.mlx, escape_hook, &data);
	mlx_close_hook(data.mlx, quit_hook, &data);
	mlx_key_hook(data.mlx, (mlx_keyfunc)move_keyhook, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long /path/to/map.ber", 2));
	so_long(argv[1]);
	return (0);
}
