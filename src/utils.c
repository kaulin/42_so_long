/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:33:14 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/09 15:09:36 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_point	set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
		ft_putendl_fd(data->map[i++], 1);
	ft_putchar_fd('\n', 1);
}

void	print_floodfill(t_data *data)
{
	int	i;
	int j;

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
