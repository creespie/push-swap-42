/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write_str(const char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

void	ft_write_int(int n)
{
	char	buf[12];
	int		i;
	int		neg;

	i = 11;
	buf[i] = '\0';
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (n == 0)
		buf[--i] = '0';
	while (n > 0)
	{
		buf[--i] = '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		buf[--i] = '-';
	write(2, buf + i, 11 - i);
}

void	ft_write_percent(double d)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(d * 100.0);
	decimal_part = (int)(d * 10000.0) % 100;
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	ft_write_int(integer_part);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_write_int(decimal_part);
}
