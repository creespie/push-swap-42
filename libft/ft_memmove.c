//
// The memmove() function copies len bytes from string src to string dst.
// The two strings may overlap; the copy is always done
// in a non-destructive manner.
//
// Return
// The memmove() function returns the original value of dst.
//
#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t	i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	if (ptr1 < ptr2)
	{
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	else
	{
		len--;
		while (0 < len)
		{
			ptr1[len] = ptr2[len];
			len--;	
		}
	}
	return (s1);
}