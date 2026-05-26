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
			|| (sign == -1 && (-result) < INT_MIN))
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}
