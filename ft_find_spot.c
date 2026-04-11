#include "push_swap.h"

static int	ft_find_return(int	i, int size_b)
{
	if (i <= size_b / 2)
		return (i);
	else
		return ((size_b - i) * -1);
}

int	ft_smallest(t_stack *stack_b, int size_b)
{
	int	i;

	i = ft_find_index(stack_b, ft_find_biggest(stack_b, size_b), size_b);
	return(ft_find_return(i, size_b));
}

int	ft_find_spot(t_stack *current, t_stack *stack_b, int size_b, int i)
{
	t_stack	*n1;
	t_stack *n2;

	n1 = stack_b;
	n2 = n1->prev;
	if (!stack_b || size_b == 0)
        return (0);
	if (ft_find_biggest(stack_b, size_b)->index < current->index)
		return (ft_smallest(stack_b, size_b));
	if (ft_find_smallest(stack_b, size_b)->index > current->index)
		return (ft_smallest(stack_b, size_b));
	n2 = n1;
	while (i <= size_b)
	{
		n1 = n2;
		n2 = n1->next;
		if (n1->index > current->index && n2->index < current->index)
			return(ft_find_return(i, size_b));
		i++;
	}
	return (0);
}
