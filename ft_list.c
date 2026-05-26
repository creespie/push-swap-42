#include "push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*
** Appends new node at the back of a non-circular list.
** Call ft_close_circle() after the list is fully built.
*/
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = ft_lstlast_ps(*lst);
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
** Counts nodes in a circular doubly-linked list.
*/
int	ft_lst_count(t_stack *stack)
{
	t_stack	*first;
	int		i;

	if (!stack)
		return (0);
	i = 1;
	first = stack;
	while (stack->next != first)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/*
** Closes the doubly-linked list into a circle.
*/
void	ft_close_circle(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return ;
	last = ft_lstlast_ps(stack);
	stack->prev = last;
	last->next = stack;
}
