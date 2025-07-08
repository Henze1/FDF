/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:19:01 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:41:36 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../headers/get_next_line.h"

static int	count_width(char *str, char c);
static void	get_dimension(char *file_name, t_map *data);
static void	map_memory(t_map *data);

void	read_file(char *filename, t_map *data)
{
	get_dimension(filename, data);
	map_memory(data);
	get_fill(filename, data);
}

static int	count_width(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		while (*str == c)
			str++;
	}
	return (count);
}

static void	get_dimension(char *file_name, t_map *data)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_error("Error:Failed to open file", data);
	data->height = 0;
	data->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (data->height == 0)
			data->width = count_width(line, ' ');
		data->height++;
		free(line);
	}
	close(fd);
	if (data->height == 0 || data->width == 0)
		exit_error("Error:Invalid or empty map", data);
}

static void	map_memory(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->points = (t_point **)malloc(sizeof(t_point *) * (data->height));
	if (!data->points)
		return ;
	while (i < data->height)
	{
		data->points[i] = (t_point *)malloc(sizeof(t_point) * (data->width));
		if (!data->points[i])
			return (kill_map(data->points, i));
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].x = j;
			data->points[i][j].y = i;
			data->points[i][j].z = 0;
			data->points[i][j].color = -1;
			j++;
		}
		i++;
	}
}
