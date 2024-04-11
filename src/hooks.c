/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:51:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 09:59:55 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Cleanly exits with a custom message if 'ESC' or 'Q' is pressed.
*/
void	escape_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		quit_success(data, "Escape is not a victory!");
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		quit_success(data, "Quitting is not a victory!");
}

/*
Cleanly exits with a custom message if window is closed.
*/
void	quit_hook(void *param)
{
	t_data	*data;

	data = param;
	quit_success(data, "Closing the window is not a victory!");
}

/*
Detects single or repeated presses of movement keys WASD (and arrow keys). 
Directs the appropriate landing coordinate to move_to function.
*/
void	move_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = data->x;
	y = data->y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_to(data, x, y - 1);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_to(data, x, y + 1);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_to(data, x - 1, y);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_to(data, x + 1, y);
	}
}
