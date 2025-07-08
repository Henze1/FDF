/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:56:01 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:39:02 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	fdf(t_map *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
			&(data->line_length), &(data->endian));
	data->zoom = 20;
	data->shift_x = WIN_WIDTH / 2;
	data->shift_y = WIN_HEIGHT / 2;
	data->rotation = 0.5;
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L << 5, close_window, data);
	mlx_loop(data->mlx_ptr);
}

int	close_window(t_map *map)
{
	if (map->points)
		kill_map(map->points, map->height);
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	free(map);
	exit(0);
	return (0);
}
