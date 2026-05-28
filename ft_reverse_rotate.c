#include "push_swap.h"

void	ft_rra(t_stack **stack_a, int flag)
{
	*stack_a = (*stack_a)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
	ft_bench_update(*stack_a, OP_RRA);
}

void	ft_rrb(t_stack **stack_b, int flag)
{
	*stack_b = (*stack_b)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
	ft_bench_update(*stack_b, OP_RRB);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
	ft_bench_update(*stack_b, OP_RRR);
}
