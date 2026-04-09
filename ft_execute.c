#include "push_swap.h"

t_stack	*ft_fastest(t_stack *stack_a, t_stack *stack_b, int size, int position)
{
	int	i;
	int	spot;
	t_stack *current;
	t_stack	*next;

	i = 0;
	current = stack_a;
	next = stack_a;
	spot = ft_find_spot(current, stack_b, ft_lst_count(stack_b), 1);
	while (i < size)
	{
		next = next->next;
		if (ft_compare(position, spot, ft_position(next, stack_a, size),
		 	ft_find_spot(next, stack_b, ft_lst_count(stack_b), 1)) == 1)
		{
			position = ft_position(next, stack_a, size);
			spot = ft_find_spot(next, stack_b, ft_lst_count(stack_b), 1);
			current = next;
		}
		i++;
	}
	return (current);
}

void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stack *fastest, int size)
{
	int	position;
	int	spot;

	position = ft_position(fastest, *stack_a, size);
	spot = ft_find_spot(fastest, *stack_b, ft_lst_count(*stack_b), 1);
	while (position > 0 && spot > 0)
	{
		ft_rr(stack_a, stack_b);
		position--;
		spot--;
	}
	while (position < 0 && spot < 0)
	{
		ft_rrr(stack_a, stack_b);
		position++;
		spot++;
	}
	while (position > 0)
	{
		ft_ra(stack_a, 1);
		position--;
	}
	while (spot > 0)
	{
		ft_rb(stack_b, 1);
		spot--;
	}
	while (position < 0)
	{
		ft_rra(stack_a, 1);
		position++;
	}
	while (spot < 0)
	{
		ft_rrb(stack_b, 1);
		spot++;
	}
	ft_pb(stack_a, stack_b);
}
