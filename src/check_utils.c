/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:00:33 by jajuntti          #+#    #+#             */
/*   Updated: 2024/04/08 10:42:59 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Returns 1 if given path is a directory and 0 if it's not.
*/
int	is_directory(char *filepath)
{
	int	fd;

	fd = open(filepath, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

/*
Marks the current point as visited, adjusts token and exit counters, returns 
true (1) if all tokens and the exit have been found. Otherwise looks 
recursively at all possile paths left, right, up and down. Returns false (0) 
if none of these paths return true.
*/
int	is_solvable(t_data *data, t_point point, int *v_col, int *v_exit)
{
	data->visited[point.y][point.x] = 1;
	if (data->map[point.y][point.x] == 'C')
		(*v_col)++;
	if (data->map[point.y][point.x] == 'E')
	{
		data->exit_point = point;
		*v_exit = 1;
	}
	if (*v_col == data->tokens && *v_exit)
		return (1);
	if ((!data->visited[point.y][point.x + 1] \
		&& data->map[point.y][point.x + 1] != '1' \
		&& is_solvable(data, set_point(point.x + 1, point.y), v_col, v_exit)) \
		|| (!data->visited[point.y][point.x - 1] \
		&& data->map[point.y][point.x - 1] != '1' \
		&& is_solvable(data, set_point(point.x - 1, point.y), v_col, v_exit)) \
		|| (!data->visited[point.y + 1][point.x] \
		&& data->map[point.y + 1][point.x] != '1' \
		&& is_solvable(data, set_point(point.x, point.y + 1), v_col, v_exit)) \
		|| (!data->visited[point.y - 1][point.x] \
		&& data->map[point.y - 1][point.x] != '1' \
		&& is_solvable(data, set_point(point.x, point.y - 1), v_col, v_exit)))
		return (1);
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
			{
				data->start_point = set_point(j, i);
				(*p)++;
			}
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
