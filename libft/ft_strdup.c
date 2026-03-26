//
// Description
// The strdup() function allocates sufficient memory
// for a copy of the string s1, does the copy, and returns a pointer to it.
// The pointer may subsequently be used as an argument to the function free(3).
// If insufficient memory is available,
// NULL is returned and errno is set to ENOMEM.
//
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen((char *)src);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, (char *)src);
	return (dst);
}