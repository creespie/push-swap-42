// param
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// #3. The adress of the function used to delete the
// content of an element if needed.

// descr
// Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed.

// return
// The new list. NULL if the allocation fails.

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *copy;
	t_list *check;

	if (lst == NULL)
		return NULL;
	copy = ft_lstnew(f(lst->content));
	if (!copy)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		check = ft_lstnew(f(lst->content));
		if (!check)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (copy);
}