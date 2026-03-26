// The memccpy() function copies bytes from string src to string dst.  
// If the character c (as converted to an unsigned char)
// occurs in the string src, 
// the copy stops and a pointer to the byte after the copy of c
// in the string dst is returned.
// Otherwise, n bytes are copied, and a NULL pointer is returned.
//
#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c,
size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned char	needle;
	size_t			i;

	needle = c;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		if (psrc[i] == needle)
			return (pdest + i + 1);
		i++;
	}
	return (NULL);
}