#include "libft.h"

void	ft_putsendl(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i]);
	ft_putchar('\n');
}
