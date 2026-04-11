#include "push_swap.h"

void	three_append(t_stack **stack)
{
	ft_ra(stack, 1);
	ft_sa(stack, 1);
	ft_rra(stack, 1);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*one;
	t_stack	*two;
	t_stack *three;

	one = *stack;
	two = one->next;
	three = two->next;
	if (one->index > two->index && two->index > three->index)
	{
		ft_ra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (one->index > two->index && one->index > three->index && two->index < three->index )
		ft_ra(stack, 1);
	else if (one->index > two->index)
		ft_sa(stack, 1);
	else if (one->index > three->index)
		ft_rra(stack, 1);
	else if (two->index > three->index)
		three_append(stack);
}

void	ft_sort_two(t_stack **stack)
{
	t_stack *one;
	t_stack	*two;

	one = *stack;
	two = one->next;
	if (one->index > two->index)
		ft_ra(stack, 1);
}

void ft_sort_few(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_rra(stack_a, 1);
		ft_highest_up(stack_b, ft_lst_count(*stack_b), 0);
		ft_b_to_a(stack_a, stack_b);
		while ((*stack_a)->index > 0)
			ft_rra(stack_a, 1);
	}
}
