#include "push_swap.h"

void	ft_pa(t_list *stack_a, t_list *stack_b)
{
	t_list 	*na;
	t_list 	*nb;
	t_list	*temp;

	nb = stack_b->next;
	if (nb == NULL)
		return (NULL);
	temp = nb->next;
	na = stack_a->next;
	stack_a->next = nb;
	nb->next = na;
	stack_b->next = temp;
}

void	ft_pb(t_list *stack_a, t_list *stack_b)
{
	t_list 	*na;
	t_list 	*nb;
	t_list	*temp;

	na = stack_a->next;
	if (na == NULL)
		return (NULL);
	temp = na->next;
	nb = stack_b->next;
	stack_b->next = na;
	na->next = nb;
	stack_a->next = temp;
}
