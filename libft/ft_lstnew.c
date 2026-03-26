// Description
// Allocates (with malloc(3)) and returns a new element.
// The variable ’content’ is initialized with the value of the parameter
// ’content’.
// The variable ’next’ is initialized to NULL.
//
// Parameters
// #1. The content to create the new element with.
//
// Return
// The new element.
//
// External functs.
// malloc
//
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return NULL;
	new->content = content;
	new->next = NULL;
	return(new);
}
