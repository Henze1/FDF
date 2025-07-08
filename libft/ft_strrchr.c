/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:02:12 by hpodratc          #+#    #+#             */
/*   Updated: 2025/01/26 19:02:16 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*ptr;

	i = 0;
	ch = (char)c;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == ch)
			ptr = (char *)&s[i];
		++i;
	}
	if (ch == '\0')
		return ((char *) &s[i]);
	return (ptr);
}
