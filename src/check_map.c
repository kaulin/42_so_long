/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:44 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 11:13:42 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"\

static void check_extension(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (map_file[len -4] != '.' || map_file[len -3] != 'b' \
		|| map_file[len -2] != 'e' || map_file[len -1] != 'r')
		quit_file_error("Map file missing .ber file extension");
}

void	check_map(char *map_file, t_map *map)
{
	int	fd;

	check_extension(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		quit_file_error("Error reading map file");
}
