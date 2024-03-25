/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:33:14 by jajuntti          #+#    #+#             */
/*   Updated: 2024/03/25 17:39:59 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void print_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
		ft_putendl_fd(data->map[i++], 1);
	ft_putchar_fd('\n', 1);
}

void	print_floodfill(t_data *data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (data->visited[i][j] == 0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd('X', 1);
			j++;
		}
		j = 0;
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}