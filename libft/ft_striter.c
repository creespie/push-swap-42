#include "libft.h"

void	*ft_striter(char *s, void (*f)(char *))
{
	int		index;
	
	index = 0;
	while (s[index])
	{
		f(&s[index]);
		index++;
	}
	return (NULL);
}