#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *nb;
	t_stack	*n_next;
	t_stack	*n_prev;

	if (*stack_b = NULL)
		return ;
	nb = *stack_b;
	n_next = nb->next;
	n_prev = nb->prev;
	n_next->prev = n_prev;
	n_prev->next = n_next;
	*stack_b = n_next;
	n_next = *stack_a;
	n_prev = n_next->prev;
	n_next->prev = nb;
	nb->next = n_next;
	n_prev->next = nb;
	nb->prev =n_prev;
	*stack_a = nb;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *na;
	t_stack	*n_next;
	t_stack	*n_prev;

	if (*stack_a = NULL)
		return ;
	na = *stack_a;
	n_next = na->next;
	n_prev = na->prev;
	n_next->prev = n_prev;
	n_prev->next = n_next;
	*stack_a = n_next;
	n_next = *stack_b;
	n_prev = n_next->prev;
	n_next->prev = na;
	na->next = n_next;
	n_prev->next = na;
	na->prev =n_prev;
	*stack_b = na;
}
