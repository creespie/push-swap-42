// param
// #1. The address of a pointer to the first link of
// a list.
// #2. The address of a pointer to the element to be
// added to the list.

// descr
// Adds the element ’new’ at the end of the list.

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!(*lst))
	{
		*lst = new;
	}
	temp = ft_lstlast(*lst);
	temp -> next = new;
	new -> next = NULL;
}
