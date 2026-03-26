#include "libft.h"

char *ft_strcat(char *dest, char *src)
{
	int	i;
	int	index;

	i = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}

