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
