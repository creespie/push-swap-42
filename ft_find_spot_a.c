#include "push_swap.h"

static int	ft_find_return(int	i, int size_a)
{
	if (i <= size_a / 2)
		return (i);
	else
		return ((size_a - i) * -1);
}

int	ft_smallest_a(t_stack *stack_a, int size_a)
{
	int	i;

	i = ft_find_index(stack_a, ft_find_smallest(stack_a, size_a), size_a);
	return(ft_find_return(i, size_a));
}

int	ft_find_spot_a(t_stack *current, t_stack *stack_a, int size_a, int i)
{
	t_stack	*n1;
	t_stack *n2;

	n1 = stack_a;
	n2 = n1;
	if (ft_find_biggest(stack_a, size_a)->index < current->index)
		return (ft_smallest_a(stack_a, size_a));
	if (ft_find_smallest(stack_a, size_a)->index > current->index)
		return (ft_smallest_a(stack_a, size_a));
	i = 1;
	while (i < size_a)
	{
		n1 = n2;
		n2 = n1->next;
		if (n1->index < current->index && n2->index > current->index)
			return(ft_find_return(i, size_a));
		i++;
	}
	return (0);
}
