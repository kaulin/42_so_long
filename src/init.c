/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:43:27 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 15:31:34 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(char *mapfile, t_map *map)
{
	map->rows = check_mapfile(mapfile);
	ft_printf("The map file has %d rows.");
}

void	init_data(t_data *data, t_map *map)
{
	return ;
}