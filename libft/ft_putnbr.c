#include "libft.h"

void	ft_putnbr(int n)
{
	char	*number;

	number = ft_itoa(n);
	ft_putstr(number);
}
