/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:59:15 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/08 21:39:22 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	exit_error(char *msg, t_map *data)
{
	ft_putendl_fd(msg, 2);
	if (data)
		spare_mem(data);
	exit(EXIT_FAILURE);
}
