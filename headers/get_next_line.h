/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <hpodratc@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:06:04 by hpodratc          #+#    #+#             */
/*   Updated: 2025/07/02 18:06:11 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define BLOCK_SIZE 4096
# define READ_ERROR -99

# include <stddef.h>
# include <unistd.h>

typedef struct s_buffer
{
	ssize_t	n;
	char	*bufp;
	char	buf[BUFFER_SIZE];
}			t_buffer;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

char		*get_next_line(int fd);

#endif
