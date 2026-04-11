#include "push_swap.h"

int	ft_position(t_stack *current, t_stack *stack_a, int size)
{
	int	i;
	t_stack	*checking;

	i = 0;
	checking = stack_a;
	checking = checking->prev;
	while (i < size)
	{
		checking = checking->next;
		if (checking == current)
		{
			if (i <= size / 2)
				return (i);
			else
				return ((size - i) * -1);
		}
		i++;
	}
	return (0);
}
