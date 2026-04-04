#include "push_swap.h"

void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;
	t_stack	*top_a;
	t_stack	*bottom_a;

	while (ft_lst_count(*stack_b) > 0)
	{
		top_b = *stack_b;
		top_a = *stack_a;
		bottom_a = top_a->prev;
		if (top_b->index > top_a->index && top_b->index > bottom_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_sa(stack_a, 1);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index < top_a->index && top_b->index < bottom_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index < top_a->index && top_b->index > bottom_a->index)
			ft_pa(stack_a, stack_b);
		else
			ft_rra(stack_a, 1);
	}
}

void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lst_count(*stack_a) > 3)
	{
		best = ft_fastest(*stack_a, *stack_b, ft_lst_count(*stack_a), 0);
		ft_execute(stack_a, stack_b, best, ft_lst_count(*stack_a));
	}
	ft_highest_up(stack_b, ft_lst_count(*stack_b), 0, 0);
	ft_sort_three(stack_a);
	ft_rra(stack_a, 1);
	ft_b_to_a(stack_a, stack_b);
	best = *stack_a;
	while (best->index > 0)
		{
		best = *stack_a;
		ft_rra(stack_a, 1);
		}
}
