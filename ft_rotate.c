#include "push_swap.h"

void	ft_ra(t_list *stack_a)
{
	t_list	*n1;
	t_list	*n_last;

	n1 = stack_a->next;
	n_last = ft_lstlast(stack_a);
	n_last->next = n1;
	stack_a->next = n_last;
}