/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:15:44 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:16:30 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	isometric(t_point *p, t_map *map);

void	transform(t_map *map, t_point *p1, t_point *p2)
{
	p1->x *= map->zoom;
	p2->x *= map->zoom;
	p1->y *= map->zoom;
	p2->y *= map->zoom;
	p1->z *= map->zoom / 10;
	p2->z *= map->zoom / 10;
	isometric(p1, map);
	isometric(p2, map);
	p1->x += map->shift_x;
	p2->x += map->shift_x;
	p1->y += map->shift_y;
	p2->y += map->shift_y;
}

static void	isometric(t_point *p, t_map *map)
{
	int	temp_x;
	int	temp_y;

	temp_x = p->x;
	temp_y = p->y;
	p->x = (temp_x - temp_y) * cos(map->rotation);
	p->y = -(p->z) + (temp_x + temp_y) * sin(map->rotation);
}