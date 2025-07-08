/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:43:08 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:05:44 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

static int	validate_file(char *filename);

int	main(int argc, char *argv[])
{
	t_map	*data;

	if (argc != 2)
		exit_error("Error: usage: ./fdf filename\n", NULL);
	if (!validate_file(argv[1]))
		exit_error("Error: File must have .fdf", NULL);
	data = (t_map *)malloc(sizeof(t_map));
	if (!data)
		exit (1);
	data->width = 0;
	data->height = 0;
	data->points = NULL;
	read_file(argv[1], data);
	fdf(data);
	spare_mem(data);
	return (0);
}

int	deal_key(int key, t_map *data)
{
	ft_putnbr_fd(key, 1);
	ft_putendl_fd("", 1);
	if (key == KEY_UP)
		data->shift_y -= 10;
	if (key == KEY_DOWN)
		data->shift_y += 10;
	if (key == KEY_LEFT)
		data->shift_x -= 10;
	if (key == KEY_RIGHT)
		data->shift_x += 10;
	if (key == MINUS && data->zoom > 1.0)
		data->zoom -= 1;
	if (key == EQUAL && data->zoom < 100)
		data->zoom += 1;
	if (key == KEY_A)
		data->rotation -= 0.1;
	if (key == KEY_D)
		data->rotation += 0.1;
	if (key == ESC)
		close_window(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->addr, WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8));
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

static int	validate_file(char *filename)
{
	char	*extension;

	if (!filename)
		return (0);
	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (0);
	return (ft_strncmp(extension, ".fdf", 4) == 0);
}
