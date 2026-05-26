#include "push_swap.h"

void	ft_ra(t_stack **stack_a, int flag)
{
	*stack_a = (*stack_a)->next;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b, int flag)
{
	*stack_b = (*stack_b)->next;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1, "rr\n", 3);
}
