// Description
// Applies the function ’f’ to each character of the string ’s’
// to create a new string (with malloc(3))resulting
// from successive applications of ’f’.
//
// Parameters
// #1. The string on which to iterate.
// #2. The function to apply to each character.
//
// Return
// The string created from the successive applications of ’f’.
// Returns NULL if the allocation fails.
//
// Externel functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		index;
	
	index = 0;
	string = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!string)
		return NULL;
	while (s[index])
	{
		string[index] = f(index, s[index]);
		index++;
	}
	string[index] = '\0';
	return (string);
}
