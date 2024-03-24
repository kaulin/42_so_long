/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:22 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/24 18:22:15 by jajuntti         ###   ########.fr       */
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
}

void	clean_data(t_data *data)
{
	if (!data)
		return ;
	clean_str_array(data->map, data->rows);
	//free(data);
}
