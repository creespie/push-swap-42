#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		index;
	
	index = 0;
	string = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!string)
		return NULL;
	while (s[index])
	{
		string[index] = f(s[index]);
		index++;
	}
	string[index] = '\0';
	return (string);
}