/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:06:40 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/02 18:06:46 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_getc(int fd);
static int	ft_putc(t_string *str, char c);

char	*get_next_line(int fd)
{
	t_string	str;
	char		c;

	str.str = NULL;
	str.len = 0;
	str.capa = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
		{
			free(str.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&str, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (str.len > 0)
		if (ft_putc(&str, '\0'))
			return (NULL);
	return (str.str);
}

static int	ft_getc(int fd)
{
	static t_buffer	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, BUFFER_SIZE);
		if (buf.n < 0)
		{
			buf.n = 0;
			return (READ_ERROR);
		}
		buf.bufp = buf.buf;
	}
	if (--buf.n >= 0)
	{
		return ((unsigned char)*buf.bufp++);
	}
	buf.n = 0;
	return (EOF);
}

static int	ft_putc(t_string *str, char c)
{
	size_t	i;
	char	*tmp;

	if (str->len + 1 > str->capa)
	{
		tmp = str->str;
		str->str = (char *)malloc((str->capa + BLOCK_SIZE) * sizeof(char));
		if (!str->str)
		{
			free(tmp);
			return (1);
		}
		i = 0;
		while (i < str->len)
		{
			str->str[i] = tmp[i];
			i++;
		}
		free(tmp);
		str->capa += BLOCK_SIZE;
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}