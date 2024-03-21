/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:48:22 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/21 14:50:14 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_map *map)
{
	if (!map)
		return ;
}

void	clean_data(t_data *data)
{
	if (!data)
		return ;
	clean_map(data->map);
}
