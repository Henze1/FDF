/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:10:21 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:32:48 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define EQUAL 61
# define MINUS 45
# define KEY_A 97
# define KEY_D 100

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		zoom;
	int		shift_x;
	int		shift_y;
	float	rotation;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_point	**points;
}			t_map;

void		kill_map(t_point **map, int index);
void		read_file(char *filename, t_map *data);
void		get_fill(char *file_name, t_map *data);
void		draw(t_map *map);
void		transform(t_map *map, t_point *p1, t_point *p2);
int			deal_key(int key, t_map *data);
void		fdf(t_map *data);
int			close_window(t_map *map);
void		exit_error(char *msg, t_map *data);
void		spare_mem(t_map *map);

#endif
