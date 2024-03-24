/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:42:09 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/24 18:34:09 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void so_long(char *mapfile)
{
	mlx_t	*mlx;
	t_data	data;

	init_data(mapfile, &data);
	quit_success(&data, "WINNER WINNER!");
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
