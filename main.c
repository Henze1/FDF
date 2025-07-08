/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:43:08 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 18:12:12 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"
#include "headers/get_next_line.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		close_hook(t_data *data);
int		esc_hook(int keycode, void *data);
int		mouse_hook(int button, int x, int y, void *param);
int		render_hook(t_data *data);

#define WIDTH 1280
#define HEIGHT 720
int	main(void)
{
	void	*init;
	void	*window;
	t_data	img;
	t_vars	vars;
	
	init = mlx_init();
	vars.mlx = init;
	window = mlx_new_window(init, WIDTH, HEIGHT, "FDF");
	vars.win = window;
	img.img = mlx_new_image(init, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.vars = &vars;
	mlx_hook(vars.win, 17, 0L, close_hook, &img);
	mlx_hook(vars.win, 2, 1L<<0, esc_hook, &img);
	// mlx_mouse_hook(vars.win, mouse_hook, &img);
	mlx_loop_hook(init, render_hook, &img);
	mlx_loop(init);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_hook(t_data *data)
{
	mlx_destroy_image(data->vars->mlx, data->img);
	mlx_destroy_window(data->vars->mlx, data->vars->win);
	mlx_destroy_display(data->vars->mlx);
	free(data->vars->mlx); 
	exit(0);
}

int	esc_hook(int keycode, void *data)
{
	t_data *mlx_data = (t_data *)data;
	
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx_data->vars->mlx, mlx_data->img);
		mlx_destroy_window(mlx_data->vars->mlx, mlx_data->vars->win);
		mlx_destroy_display(mlx_data->vars->mlx);
		free(mlx_data->vars->mlx); 
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	printf("Button %d pressed.\n",button);
	printf("Mouse moving, at %dx%d.\n",x,y);
	return (0);
	(void)param;
}


int	render_hook(t_data *data)
{
	static int		i = -1;
	int		trgb;
	int		X = WIDTH / 2;
	int		Y = HEIGHT / 2;

	++i;
	trgb = create_trgb(0, 255, 0, 255);
	my_mlx_pixel_put(data, X + i + 1, Y, trgb);
	mlx_put_image_to_window(data->vars->mlx, data->vars->win, data->img, 0, 0);
	if (i == 1500)
	{
		mlx_destroy_image(data->vars->mlx, data->img);
		mlx_destroy_window(data->vars->mlx, data->vars->win);
		mlx_destroy_display(data->vars->mlx);
		free(data->vars->mlx); 
		mlx_loop_end(data->vars->mlx);
	}
	return (0);
	(void)data;
}