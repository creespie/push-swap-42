#include "push_swap.h"

t_stack	*ft_lstnew_adapt(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!(new))
		return NULL;
	new->content = content;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

void ft_lstadd_back_adapt(t_stack **lst, t_stack *new)
{
	t_stack *temp;

	temp = ft_lstlast(*lst);
	temp -> next = new;
	new->prev = temp;
	new -> next = NULL;
}