#include "push_swap.h"

int	ft_find_index(t_stack *stack, t_stack *to_find, int size)
{
	int	i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (i < size)
	{
		if (current == to_find)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

t_stack	*ft_find_biggest(t_stack *stack, int size)
{
	int	loop;
	t_stack	*current;
	t_stack	*biggest;

	loop = 1;
	current = stack;
	biggest = current;
	while(loop < size)
	{
		current = current->next;
		if (biggest->index < current->index)
			biggest = current;
		loop++;
	}
	return (biggest);
}

t_stack	*ft_find_smallest(t_stack *stack, int size)
{
	int	loop;
	t_stack	*current;
	t_stack	*smallest;

	loop = 1;
	current = stack;
	smallest = current;
	while(loop < size)
	{
		current = current->next;
		if (smallest->index > current->index)
			smallest = current;
		loop++;
	}
	return (smallest);
}
