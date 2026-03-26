#include <stdlib.h>
#include "libft.h"

int	ft_set_sign(int *n)
{
	int	sign;

	if (*n < 0)
	{
		sign = -1;
		*n = *n * -1;
	}
	else
		sign = 1;
	return (sign);
}

int	ft_count_malloc(int n)
{
	int	counter;
	
	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

void ft_fill(char *string, int n, int counter)
{
	string[counter] = '\0';
	counter--;
	while (n > 0)
	{
		string[counter] = (n % 10) + '0';
		n = n / 10;
		counter--;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	int		sign;
	int		counter;


	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return(ft_strdup("0"));
	sign = ft_set_sign(&n);
	counter = ft_count_malloc(n);
	if (sign < 0)
		counter++;
	string = (char *)malloc((counter + 1) * sizeof(char));
	ft_fill(string, n, counter);
	if (sign < 0)
		string[0] = '-';
	return (string);
}
