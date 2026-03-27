#include "push_swap.h"

void	ft_sa(t_list *stack_a)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*temp;

	if (ft_lstsize(stack_a) < 3)
}

void	ft_sb(t_list *stack_b)
{
	t_list	*n1;
	t_list	*n2;

	n1 = stack_b->next;
	n2 = n1->next;
	if (n1 == NULL || n2 == NULL)
		return (NULL);
	n2->next = n1;
	stack_b->next = n2;
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
