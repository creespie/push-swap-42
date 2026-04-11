#include "push_swap.h"

void	ft_execute_append_both(t_stack **stack_a, t_stack **stack_b, int *position, int *spot)
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

void	ft_exe_app_pos(t_stack **stack_a, int *position)
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

void	ft_exe_app_spot(t_stack **stack_b, int *spot)
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

void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stack *fastest, int size)
{
	int	position;
	int	spot;

	position = ft_position(fastest, *stack_a, size);
	spot = ft_find_spot(fastest, *stack_b, ft_lst_count(*stack_b), 1);
	while (position > 0 && spot > 0)
		ft_execute_append_both(stack_a, stack_b, &position, &spot);
	while (position < 0 && spot < 0)
		ft_execute_append_both(stack_a, stack_b, &position, &spot);
	while (position > 0)
		ft_exe_app_pos(stack_a, &position);
	while (spot > 0)
		ft_exe_app_spot(stack_b, &spot);
	while (position < 0)
		ft_exe_app_pos(stack_a, &position);
	while (spot < 0)
		ft_exe_app_spot(stack_b, &spot);
	ft_pb(stack_a, stack_b);
}
