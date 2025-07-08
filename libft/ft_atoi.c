/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:47:52 by hpodratc          #+#    #+#             */
/*   Updated: 2025/04/30 09:56:38 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	is_neg;

	i = 0;
	num = 0;
	is_neg = 1;
	while (is_space(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg *= -1;
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		++i;
	}
	return (num * is_neg);
}

static int	is_space(int c)
{
	if (c == 9 || c == 10
		|| c == 11 || c == 12
		|| c == 13 || c == 32)
		return (c);
	return (0);
}
