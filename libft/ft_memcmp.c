//
//The memcmp() function compares byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.
//
// Return
// The memcmp() function returns zero if the two strings are identical, 
// otherwise returns the difference between the first two differing bytes
// (treated as unsigned char values,
// so that `\200' is greater than `\0', for example).
// Zero-length strings are always identical.
// This behavior is not required by C and portable code should
// only depend on the sign of the returned value.
//
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps2;
	unsigned char	*ps1;
	size_t			i;

	ps2 = (unsigned char *)s2;
	ps1 = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (ps2[i] != ps1[i])
			return (ps2[i]- ps1[i]);
		i++;
	}
	return (0);
}