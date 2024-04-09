/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:22 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/09 15:05:15 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_str_array(char **array, int rows)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < rows)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	clean_mlx(t_data *data)
{
	
	if (!data->mlx)
		return ;
	mlx_delete_image(data->mlx, data->img_player);
	mlx_delete_image(data->mlx, data->img_wall);
	mlx_delete_image(data->mlx, data->img_token);
	mlx_delete_image(data->mlx, data->img_exit);
	mlx_delete_image(data->mlx, data->img_empty);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
}

void	clean_data(t_data *data)
{
	if (!data)
		return ;
	clean_mlx(data);
	clean_str_array(data->map, data->rows);
	clean_str_array(data->visited, data->rows);
}
