//
// Description
// Allocates (with malloc(3)) and returns a copy of ’s1’
// with the characters specified in ’set’ 
// removed from the beginning and the end of the string.
//
// Parameters
// #1. The string to be trimmed.
// #2. The reference set of characters to trim.
//
// Return
// The trimmed string. NULL if the allocation fails.
//
// External functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

int	ft_check_string(char const *string, char const letter)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == letter)
			return(1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		total_start;
	int		total_end;

	index = 0;
	total_start = 0;
	total_end = ft_strlen((char *)s1);
	while (s1[index] && ft_check_string(set, s1[index]))
	{
		total_start++;
		index++;
	}
	while (s1[index])
		index++;
	index--;
	while (index > 0 && ft_check_string(set, s1[index]))
	{
		index--;
		total_end--;
	}
	return (ft_substr(s1, total_start, (total_end - total_start)));
}