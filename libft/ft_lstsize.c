
// param
// #1. The beginning of the list.
// desc
// Counts the number of elements in a list.

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
