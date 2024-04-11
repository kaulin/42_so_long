/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:22 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/11 10:07:53 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Frees the elements of a string array of n elements, frees the array 
itself and sets it to NULL.
*/
static void	clean_str_array(char **array, int n)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < n)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

/*
If mlx has been initialized, frees any initialized images.
*/
void	clean_mlx(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->img_player)
		mlx_delete_image(data->mlx, data->img_player);
	if (data->img_wall)
		mlx_delete_image(data->mlx, data->img_wall);
	if (data->img_token)
		mlx_delete_image(data->mlx, data->img_token);
	if (data->img_exit)
		mlx_delete_image(data->mlx, data->img_exit);
	if (data->img_empty)
		mlx_delete_image(data->mlx, data->img_empty);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
}

/*
Cleans mlx and frees allocated memory.
*/
void	clean_data(t_data *data)
{
	if (!data)
		return ;
	clean_mlx(data);
	if (data->map)
		clean_str_array(data->map, data->rows);
	if (data->visited)
		clean_str_array(data->visited, data->rows);
}
