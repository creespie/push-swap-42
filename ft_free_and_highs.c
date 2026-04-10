#include "push_swap.h"

void	ft_free_stack(t_stack **stack, int size)
{
	int	i;
	t_stack	*to_free;
	t_stack	*temp;

	i = 0;
	to_free = *stack;
	while (i < size)
	{
		temp = to_free->next;
		free(to_free);
		to_free = temp;
		i++;
	}
	*stack = NULL;
}

void	ft_highest_up(t_stack **stack_b, int size, 	int	i)
{
	if (ft_find_biggest(*stack_b, size) == *stack_b)
		return ;
	else
	{
		i = ft_find_index(*stack_b, ft_find_biggest(*stack_b, size), size);
		while (i <= size / 2 && i > 0)
		{
			ft_rb(stack_b, 1);
			i--;
		}
		while (i > size / 2 && i < size)
		{
			ft_rrb(stack_b, 1);
			i++;
		}
	}
}

void	ft_highest_app(t_stack **stack_b, int *position, int flag)
{
	if (flag == 0)
	{
		ft_rb(stack_b, 1);
		(*position)--;
	}
	else if (flag == 1)
	{
		ft_rrb(stack_b, 1);
		(*position)++;
	}
}
