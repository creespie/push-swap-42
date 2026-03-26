//
// The memchr() function locates the first occurrence of c
// (converted to an unsigned char) in string s.
//
// Return
// The memchr() function returns a pointer to the byte located,
// or NULL if no such byte exists within n bytes.
//
#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *ptr;
    unsigned int    i;
    unsigned char   letter;

    i = 0;
    letter = c;
    ptr = (unsigned char *)s;
    while (i < n)
    {
        if (ptr[i] == letter)
            return (&ptr[i]);
        i++;
    }
    return (NULL);
}