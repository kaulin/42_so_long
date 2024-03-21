/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:44 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 15:45:13 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"\

int	check_mapfile(char *mapfile)
{
	int		fd;
	int		len;
	int		rows;
	char	*line;

	rows = 0;
	len = ft_strlen(mapfile);
	if (mapfile[len -4] != '.' || mapfile[len -3] != 'b' \
		|| mapfile[len -2] != 'e' || mapfile[len -1] != 'r')
		quit_error(NULL, "Map file missing \".ber\" extension");
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		quit_file_error("Error reading map file");
	line = ft_get_next_line(fd);
	while(line)
	{
		rows++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	if (rows == 0)
		quit_map_error(NULL, "Map file is empty");
	return (rows);
}
