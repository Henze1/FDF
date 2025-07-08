/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:57:10 by hpodratc          #+#    #+#             */
/*   Updated: 2025/01/26 19:40:26 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1p;
	char	*s2p;

	if (!n)
		return (0);
	i = 0;
	s1p = (char *)s1;
	s2p = (char *)s2;
	while (i < n)
	{
		if (s1p[i] != s2p[i])
			return ((unsigned char)s1p[i]
				- (unsigned char)s2p[i]);
		++i;
	}
	return (0);
}
