/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static int	ft_putstr_count(const char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}

static int	ft_handle_number(int fd, char spec, va_list args)
{
	if (spec == 'd' || spec == 'i')
		ft_putnbr_fd((long)va_arg(args, int), fd);
	else if (spec == 'f')
		ft_putnbr_fd((long)va_arg(args, double), fd);
	else
		return (0);
	return (1);
}

static int	ft_handle_format(int fd, char spec, va_list args)
{
	char	c;

	if (spec == 's')
		return (ft_putstr_count(va_arg(args, char *), fd));
	if (spec == 'd' || spec == 'i' || spec == 'f')
		return (ft_handle_number(fd, spec, args));
	if (spec == 'c')
	{
		c = (char)va_arg(args, int);
		write(fd, &c, 1);
		return (1);
	}
	if (spec == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_handle_format(fd, format[i], args);
		}
		else
			write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
