/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:44 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/25 17:14:19 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"\

/*
Checks that each row has there are at least 3 columns and that all rows have 
the same number of columns.
*/
void	check_cols(t_data *data)
{
	int	i;

	i = 0;
	data->cols = ft_strlen(data->map[i]);
	if (data->cols < 3)
		quit_data_error(data, "Invalid map: less than three columns");
	while (++i < data->rows)
	{
		if (ft_strlen(data->map[i]) != data->cols)
			quit_data_error(data, "Invalid map: uneven row lengths");
	}
}

/*
Checks that the map is surrounded by walls.
*/
void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (data->map[i][j] != '1' && (i == 0 || i == data->rows - 1 \
				|| j == 0 || j == data->cols - 1))
				quit_data_error(data, "Invalid map: not surrounded by walls");
			j++;
		}
		j = 0;
		i++;
	}
}

/*
Checks that the map only contains characters "01CEP", there is only one start 
and end, and at least one object.
*/
void	check_chars(t_data *data)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_chars(data, &p, &e, &c);
	if (p < 1)
		quit_data_error(data, "Invalid map: no starting position");
	if (p > 1)
		quit_data_error(data, "Invalid map: multiple starting positions");
	if (e < 1)
		quit_data_error(data, "Invalid map: no map exit");
	if (e > 1)
		quit_data_error(data, "Invalid map: multiple map exits");
	if (c < 1)
		quit_data_error(data, "Invalid map: need at least one collectible");
	data->col_count = c;
}

/*
Checks that the player can reach all the objects and the exit from their 
starting position.
*/
void	check_access(t_data *data)
{
	int	v_col;
	int	v_exit;
	int	solved;
	int	i;

	v_col = 0;
	v_exit = 0;
	i = 0;
	data->visited = calloc(data->rows, sizeof(char*));
	if (!data->visited)
		quit_data_perror(data, "Memory allocation error");
	while (i < data->rows)
	{
		data->visited[i++] = calloc(data->cols, sizeof(char)); // TODO MALLOC CHECK
	}
	solved = is_solvable(data, data->start_point, &v_col, &v_exit);
	free(data->visited);
	if (!solved)
	{
		if (!v_exit)
			quit_data_error(data, "Invalid map: no path to exit");
		if (!v_col)
			quit_data_error(data, "Invalid map: no path to all collectables");
	}
}

/*
Checks mapfile extension, opens map file and reads through its rows, keeping 
track of how many there are. Quits with appropriate error messages, if 
necessary, otherwise returns the number of rows.
*/
int	check_mapfile(t_data *data, char *mapfile)
{
	int		len;
	int		rows;
	char	*line;

	rows = 0;
	len = ft_strlen(mapfile);
	if (mapfile[len -4] != '.' || mapfile[len -3] != 'b' \
		|| mapfile[len -2] != 'e' || mapfile[len -1] != 'r')
		quit_error("Map file missing \".ber\" extension");
	data->fd = open(mapfile, O_RDONLY);
	if (data->fd == -1)
		quit_perror("Error reading map file");
	line = ft_get_next_line(data->fd);
	while(line)
	{
		rows++;
		free(line);
		line = ft_get_next_line(data->fd);
	}
	close(data->fd);
	if (rows == 0)
		quit_error("Map file is empty");
	if (rows < 3)
		quit_error("Invalid map: less than three rows");
	return (rows);
}
