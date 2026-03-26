/*
** Description
** Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
**subs
** Parameters
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
**
** Return
** The substring. NULL if the allocation fails.
**
** External functs.
** malloc
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t		index;

	index = 0;
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (index < len)
	{
		arr[index] = s[start + index];
		index++;
	}
	arr[index] = '\0';
	return (arr);
}