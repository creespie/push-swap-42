#include "push_swap.h"

static void	ft_exec_a(t_stack **stack_a, int *position)
{
	if (*position > 0)
	{
		ft_ra(stack_a, 1);
		(*position)--;
	}
	else
	{
		ft_rra(stack_a, 1);
		(*position)++;
	}
}
/*
** Finds the smallest element in a and pushes it to b until there is
** only the biggest element left in a. Then pushes everything back
** into a.
*/
void	ft_ins_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;
	int	final_b_size;

	size = ft_lst_count(*stack_a);
	final_b_size = size - 1;
	while (size > 1)
	{
		pos = ft_position(ft_find_smallest(*stack_a, size), *stack_a, size);
		while (pos != 0)
			ft_exec_a(stack_a, &pos);
		ft_pb(stack_a, stack_b);
		size--;
	}
	while (final_b_size > 0)
	{
		ft_pa(stack_a, stack_b);
		final_b_size--;
	}
}