
// param
// #1. The beginning of the list.
// desc
// Returns the last element of the list.

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return(lst);
}