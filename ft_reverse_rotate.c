#include "push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	*stack_a = temp->prev;
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	*stack_b = temp->prev;
}

void	ft_rrr(t_stack **stack_b, t_stack **stack_a)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}