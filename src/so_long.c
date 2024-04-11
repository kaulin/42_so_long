/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 10:28:15 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Draws the image for the provided character at the given coordinate, which is 
calculated using provided indexes and the tile size used.
*/
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

/*
Draws all tiles of the map.
*/
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

/*
Moves the player to the target coordinate and incremenets the move counter, 
provided the target is not a wall. The previous tile is set to empty if it 
was not the exit tile. Previous tile and new tile are redrawn. If new tile 
is the exit and all collectibles have been found, quits with victory message. 
If new tile is collectible, subtracts from the token counter.
*/
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

/*
Initializes data, draws the map, sets up hooks and starts mlx_loop.
*/
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

/*
Checks that the program is given the appropriate number of arguments (1).
*/
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long /path/to/map.ber", 2));
	so_long(argv[1]);
	return (0);
}
