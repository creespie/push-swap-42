#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;

	one = *stack_a;
	two = one->next;
	if (one->index > two->index)
		ft_sa(stack_a, 1);
}

static void	three_append(t_stack **stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}

/*
** Sorts exactly 3 elements in stack_a in ascending order.
** Cases (top=one, mid=two, bot=three):
**   [3,2,1]: ra + sa  => [2,1,3] -> [1,2,3]
**   [3,1,2]: ra       => [1,2,3]
**   [2,1,3]: sa       => [1,2,3]
**   [2,3,1]: rra      => [1,2,3]
**   [1,3,2]: three_append: ra,sa,rra => [1,2,3]
*/
void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = *stack_a;
	two = one->next;
	three = two->next;
	if (one->index > two->index && two->index > three->index)
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (one->index > two->index && one->index > three->index
		&& two->index < three->index)
		ft_ra(stack_a, 1);
	else if (one->index > two->index)
		ft_sa(stack_a, 1);
	else if (one->index > three->index)
		ft_rra(stack_a, 1);
	else if (two->index > three->index)
		three_append(stack_a);
}

/*
** Sorts 4 elements:
** push one to b, sort 3 in a, find correct spot for b's top, push back.
*/
void	ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pos;

	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_highest_up(stack_b, ft_lst_count(*stack_b));
		pos = ft_find_spot_a(*stack_b, *stack_a, ft_lst_count(*stack_a));
		while (pos > 0)
		{
			ft_ra(stack_a, 1);
			pos--;
		}
		while (pos < 0)
		{
			ft_rra(stack_a, 1);
			pos++;
		}
		ft_pa(stack_a, stack_b);
		while ((*stack_a)->index != 0)
			ft_rra(stack_a, 1);
	}
}

/*
** Reinserts all elements from stack_b back into stack_a in ascending order.
** stack_b is in descending order, so each push from b's top lands correctly.
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
** 4. Bring b's biggest to top (maintain descending invariant).
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
