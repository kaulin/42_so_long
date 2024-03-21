/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 15:42:35 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_up(t_data *data, t_map *map)
{
	return ;
}

static void so_long(char *mapfile)
{
	t_map	map;
	mlx_t	*mlx;
	t_data	data;

	init_map(mapfile, &map);
	init_data(&data, &map);
	/*
	mlx_init(1920, 1080, "Hello world!", true);
	mlx_loop(mlx);
	*/
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long /path/to/map.ber", 2));
	so_long(argv[1]);
	return (0);
}
