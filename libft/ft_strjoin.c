//
// Description
// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of ’s1’ and ’s2’.
//
// Parameter
// #1. The prefix string.
// #2. The suffix string.
//
// Return
// The new string. NULL if the allocation fails.
//
// External functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		str[index + ft_strlen((char *)s1)] = s2[index];
		index++;
	}
	str[index + ft_strlen((char *)s1)] = '\0';
	return (str);
}