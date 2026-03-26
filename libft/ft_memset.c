#include <string.h>

void *ft_memset(void *s, int c, size_t size)
{
	unsigned char *ptr;
	size_t i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < size)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
