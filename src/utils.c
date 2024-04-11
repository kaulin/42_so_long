/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:33:14 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 10:31:14 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Converts a .png file into a texture and then converts that texture into an 
MLX image.
*/
mlx_image_t	*convert_png(t_data *data, char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(file);
	if (!texture)
		quit_data_perror(data, "MLX42 failed");
	img = mlx_texture_to_image(data->mlx, texture);
	if (!img)
		quit_data_perror(data, "MLX42 failed");
	mlx_delete_texture(texture);
	return (img);
}

/*
Initializes a new point struct with given x and y coordinates.
*/
t_point	set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

/*
Prints the map array of given data struct into standard output.
*/
void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
		ft_putendl_fd(data->map[i++], 1);
	ft_putchar_fd('\n', 1);
}

/*
Prints the visited  array of given data struct into standard output.
*/
void	print_floodfill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (data->visited[i][j] == 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd('X', 1);
			j++;
		}
		j = 0;
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
