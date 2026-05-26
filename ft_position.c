#include "push_swap.h"

/*
** Returns the signed rotation cost to bring 'current' to the top of stack_a.
** Positive = rotate forward (ra), negative = reverse rotate (rra).
*/
int	ft_position(t_stack *current, t_stack *stack_a, int size)
{
	t_stack	*checking;
	int		i;

	i = 0;
	checking = stack_a;
	while (i < size)
	{
		if (checking == current)
		{
			if (i <= size / 2)
				return (i);
			else
				return ((size - i) * -1);
		}
		checking = checking->next;
		i++;
	}
	return (0);
}
