/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:51:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/09 15:14:55 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	escape_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		quit_success(data, "Escape is not a victory!");
}

void	quit_hook(void *param)
{
	t_data *data;

	data = param;
	quit_success(data, "Closing the window is not a victory!");
}

void	move_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = data->x;
	y = data->y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			move_to(data, x, y - 1);
		if (keydata.key == MLX_KEY_S)
			move_to(data, x, y + 1);
		if (keydata.key == MLX_KEY_A)
			move_to(data, x - 1, y);
		if (keydata.key == MLX_KEY_D)
			move_to(data, x + 1, y);
	}
}
