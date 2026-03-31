#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	temp = *stack_a;
	*stack_a = temp->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b, int flag)
{
	t_stack	*temp;

	temp = *stack_b;
	*stack_b = temp->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_b, t_stack **stack_a)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}