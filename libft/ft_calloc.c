/*
** The calloc() function contiguously allocates enough space for count objects
** that are size bytes of 
** memory each and returns a pointer to the allocated memory. 
** The allocated memory is filled with bytes of value zero (0).
*/
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}