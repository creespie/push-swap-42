#include "push_swap.h"

/*
** Detaches the top of stack_b and prepends it to stack_a.
*/
void	ft_cpa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*nb;
	t_stack	*n_next;
	t_stack	*n_prev;

	if (!*stack_b)
		return ;
	nb = *stack_b;
	n_next = nb->next;
	n_prev = nb->prev;
	n_next->prev = n_prev;
	n_prev->next = n_next;
	if (nb->next == nb)
		*stack_b = NULL;
	else
		*stack_b = n_next;
	if (!*stack_a)
	{
		nb->next = nb;
		nb->prev = nb;
		*stack_a = nb;
	}
	else
	{
		n_next = *stack_a;
		n_prev = n_next->prev;
		n_next->prev = nb;
		nb->next = n_next;
		n_prev->next = nb;
		nb->prev = n_prev;
		*stack_a = nb;
	}
	ft_bench_update(*stack_a, OP_PA);
}

/*
** Detaches the top of stack_a and prepends it to stack_b.
*/
void	ft_cpb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*na;
	t_stack	*n_next;
	t_stack	*n_prev;

	if (!*stack_a)
		return ;
	na = *stack_a;
	n_next = na->next;
	n_prev = na->prev;
	n_next->prev = n_prev;
	n_prev->next = n_next;
	if (na->next == na)
		*stack_a = NULL;
	else
		*stack_a = n_next;
	if (!*stack_b)
	{
		na->next = na;
		na->prev = na;
		*stack_b = na;
	}
	else
	{
		n_next = *stack_b;
		n_prev = n_next->prev;
		n_next->prev = na;
		na->next = n_next;
		n_prev->next = na;
		na->prev = n_prev;
		*stack_b = na;
	}
	ft_bench_update(*stack_b, OP_PB);
}

void	ft_crrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	ft_bench_update(*stack_b, OP_RRR);
}

void	ft_crr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	ft_bench_update(*stack_b, OP_RR);
}