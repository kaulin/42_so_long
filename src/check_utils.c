/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:00:33 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/24 18:32:51 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Returns true (1) if there is a valid path between two points in the map, 
or false (0) if there isn't.
*/
int	path_exists(t_data *data, char **map, t_point start, t_point dest)
{
	return (0);
}

/*
Returns the number of specific characters in the map.
*/
void	count_chars(t_data *data, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (!ft_strchr("01PEC", data->map[i][j]))
				quit_data_error(data, "Invalid map: forbidden characters");
			if (data->map[i][j] == 'P')
				(*p)++;
			else if (data->map[i][j] == 'E')
				(*e)++;
			else if (data->map[i][j] == 'C')
				(*c)++;
			j++;
		}
		j = 0;
		i++;
	}
}
