#include "push_swap.h"

/*
** When both stacks need to rotate the same direction,
** use the combined rr / rrr instruction.
*/
static void	ft_exec_both(t_stack **stack_a, t_stack **stack_b,
	int *position, int *spot)
{
	if (*position > 0)
	{
		ft_rr(stack_a, stack_b);
		(*position)--;
		(*spot)--;
	}
	else
	{
		ft_rrr(stack_a, stack_b);
		(*position)++;
		(*spot)++;
	}
}

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

static void	ft_exec_b(t_stack **stack_b, int *spot)
{
	if (*spot > 0)
	{
		ft_rb(stack_b, 1);
		(*spot)--;
	}
	else
	{
		ft_rrb(stack_b, 1);
		(*spot)++;
	}
}

void	ft_execute(t_stack **stack_a, t_stack **stack_b,
	t_stack *fastest, int size)
{
	int	position;
	int	spot;

	position = ft_position(fastest, *stack_a, size);
	spot = ft_find_spot(fastest, *stack_b, ft_lst_count(*stack_b));
	while (position > 0 && spot > 0)
		ft_exec_both(stack_a, stack_b, &position, &spot);
	while (position < 0 && spot < 0)
		ft_exec_both(stack_a, stack_b, &position, &spot);
	while (position > 0)
		ft_exec_a(stack_a, &position);
	while (position < 0)
		ft_exec_a(stack_a, &position);
	while (spot > 0)
		ft_exec_b(stack_b, &spot);
	while (spot < 0)
		ft_exec_b(stack_b, &spot);
	ft_pb(stack_a, stack_b);
}
