#include "push_swap.h"

int	ft_check_order(t_stack *stack, int size)
{
	int	i;
	t_stack	*check;
	
	check = stack;
	i = 0;
	while (i < size)
	{
		if (check->index == i)
		{
			check = check->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	ft_check_double(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
