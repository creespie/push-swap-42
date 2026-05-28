// libft.c
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_safe(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = (result * 10) + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

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

static void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

static int	ft_handle_format(int fd, char spec, va_list args)
{
	char	*s;
	int		count;
	char	c;

	count = 0;
	if (spec == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, fd);
		while (*s++)
			count++;
	}
	else if (spec == 'd' || spec == 'i')
	{
		ft_putnbr_fd((long)va_arg(args, int), fd);
		count++;
	}
	else if (spec == 'f')
	{
		ft_putnbr_fd((long)va_arg(args, double), fd);
		count++;
	}
	else if (spec == 'c')
	{
		c = (char)va_arg(args, int);
		write(fd, &c, 1);
		count++;
	}
	else if (spec == '%')
	{
		write(fd, "%", 1);
		count++;
	}
	return (count);
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