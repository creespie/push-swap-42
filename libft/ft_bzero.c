/*
**  The bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/
#include "libft.h"
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
