//
// Description
// The strnstr() function locates the first occurrence of the
// null-terminated string needle in the string haystack, 
// where not more than len characters are searched.
// Characters that appear after a `\0' character are not searched.
// Since the strnstr() function is a FreeBSD specific API,
// it should only be used when portability is not a concern.
//
// Return 
// If needle is an empty string, haystack is returned;
// if needle occurs nowhere in haystack, NULL is returned;
// otherwise a pointer to the first character of the first occurrence of needle
// is returned.
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
			j++;
		if (j == ft_strlen((char *)needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return NULL;
}