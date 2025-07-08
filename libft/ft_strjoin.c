/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:59:33 by hpodratc          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:58 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new_s = (char *)malloc(s1len + s2len + 1);
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s1, s1len);
	ft_memcpy(new_s + s1len, s2, s2len);
	new_s[s1len + s2len] = '\0';
	free(s1);
	return (new_s);
}
