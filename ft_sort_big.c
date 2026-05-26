#include "push_swap.h"

/*
** Rotates stack_a to the correct spot and pushes stack_b's top into it.
*/
static void	ft_right_rotation(t_stack **stack_a, t_stack **stack_b)
{
	int	number;

	number = ft_find_spot_a(*stack_b, *stack_a, ft_lst_count(*stack_a));
	while (number > 0)
	{
		ft_ra(stack_a, 1);
		number--;
	}
	while (number < 0)
	{
		ft_rra(stack_a, 1);
		number++;
	}
	ft_pa(stack_a, stack_b);
}

/*
** Reinserts all elements from stack_b back into stack_a in ascending order.
** stack_b is in descending order, so each push from b top lands in the right
** position in a.
*/
void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;
	t_stack	*top_a;
	t_stack	*bot_a;

	while (ft_lst_count(*stack_b) > 0)
	{
		top_b = *stack_b;
		top_a = *stack_a;
		bot_a = top_a->prev;
		if (top_b->index > top_a->index && top_b->index > bot_a->index)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a, 1);
		}
		else if (top_b->index > top_a->index && top_b->index < bot_a->index)
			ft_right_rotation(stack_a, stack_b);
		else if (top_b->index < top_a->index && top_b->index > bot_a->index)
			ft_pa(stack_a, stack_b);
		else
			ft_right_rotation(stack_a, stack_b);
	}
}

/*
** Main sorting algorithm for 5+ elements:
** 1. Push 2 elements to b to seed it (ensure b starts in descending order).
** 2. Repeatedly push the cheapest element from a to b until 3 remain in a.
** 3. Sort the 3 remaining elements in a.
** 4. Bring b's biggest to top (ensure descending invariant).
** 5. Reinsert all of b back into a.
** 6. Final rotate to put index 0 on top.
*/
void	ft_sort_everything(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->index < (*stack_b)->next->index)
		ft_rb(stack_b, 1);
	while (ft_lst_count(*stack_a) > 3)
	{
		best = ft_fastest(*stack_a, *stack_b, ft_lst_count(*stack_a));
		ft_execute(stack_a, stack_b, best, ft_lst_count(*stack_a));
	}
	ft_sort_three(stack_a);
	ft_highest_up(stack_b, ft_lst_count(*stack_b));
	ft_b_to_a(stack_a, stack_b);
	while ((*stack_a)->index != 0)
		ft_rra(stack_a, 1);
}
