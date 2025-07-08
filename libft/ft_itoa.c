/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:55:08 by hpodratc          #+#    #+#             */
/*   Updated: 2025/01/27 09:27:51 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n);
static void	set_s(char *s, int len, int n, int sign);
static char	*case_zero(void);
static char	*case_int_min(void);

char	*ft_itoa(int n)
{
	char	*str;
	int		dig_cnt;
	int		sign;

	dig_cnt = 0;
	sign = 0;
	if (n == 0)
		return (case_zero());
	if (n == -2147483648)
		return (case_int_min());
	if (n < 0)
	{
		sign = 1;
		dig_cnt = 1;
		n *= -1;
	}
	dig_cnt += num_len(n);
	str = (char *)malloc((dig_cnt + 1) * sizeof(char));
	if (!str)
		return (NULL);
	set_s(str, dig_cnt, n, sign);
	return (str);
}

static int	num_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static void	set_s(char *s, int len, int n, int sign)
{
	int		i;
	char	t;

	i = 0;
	while (i < len)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		++i;
	}
	if (sign)
		s[i - 1] = '-';
	i = 0;
	while (i < len / 2)
	{
		t = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = t;
		++i;
	}
	s[len] = '\0';
}

static char	*case_zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*case_int_min(void)
{
	char	*str;
	int		dig_cnt;

	dig_cnt = 13;
	str = (char *)malloc((dig_cnt + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", dig_cnt);
	str[dig_cnt] = '\0';
	return (str);
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa(0));
}*/
