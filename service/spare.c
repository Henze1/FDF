/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spare.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:33:12 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:39:35 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	kill_map(t_point **map, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	spare_mem(t_map *map)
{
	if (map)
	{
		if (map->points)
			kill_map(map->points, map->height);
		if (map->mlx_ptr)
		{
			if (map->img_ptr)
				mlx_destroy_image(map->mlx_ptr, map->img_ptr);
			if (map->win_ptr)
				mlx_destroy_window(map->mlx_ptr, map->win_ptr);
			mlx_destroy_display(map->mlx_ptr);
			free(map->mlx_ptr);
		}
		free(map);
	}
}
