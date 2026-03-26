#include "libft.h"

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	index;

	i = ft_strlen(dest);
	index = 0;
	while (src[index] && index < nb)
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}
