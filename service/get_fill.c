/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:23:29 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:40:29 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"
#include "../headers/get_next_line.h"

static int	ft_atoi_base(char *str, int base);
static void	free_resources(char **array, char *ptr);
static void	parse_point(char *str, t_point *point);
static void	process_line(char **nums, t_map *data, int row);

void	get_fill(char *file_name, t_map *data)
{
	char	*line;
	char	**nums;
	int		i;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_error("Error: Failed to open file", data);
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		nums = ft_split(line, ' ');
		if (!nums)
		{
			free(line);
			exit_error("Error: Memory allocation failed", data);
		}
		process_line(nums, data, i);
		free_resources(nums, line);
		i++;
	}
	close(fd);
}

static int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	result;
	int	digit;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		i++;
	}
	return (result);
}

static void	free_resources(char **array, char *ptr)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	if (ptr)
		free(ptr);
}

static void	parse_point(char *str, t_point *point)
{
	char	**split;

	if (ft_strchr(str, ','))
	{
		split = ft_split(str, ',');
		if (!split)
			return ;
		point->z = ft_atoi(split[0]);
		if (split[1])
		{
			if (ft_strncmp(split[1], "0x", 2) == 0)
				point->color = ft_atoi_base(split[1] + 2, 16);
			else
				point->color = ft_atoi_base(split[1], 16);
		}
		else
			point->color = -1;
		free_resources(split, NULL);
	}
	else
	{
		point->z = ft_atoi(str);
		point->color = -1;
	}
}

static void	process_line(char **nums, t_map *data, int row)
{
	int	i;

	i = 0;
	while (i < data->width && nums[i])
	{
		parse_point(nums[i], &data->points[row][i]);
		i++;
	}
}
