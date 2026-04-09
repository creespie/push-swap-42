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

void	ft_highest_up(t_stack **stack_b, int size, 	int	i, int	position)
{
	int	highest_index;
	t_stack	*current;

	position = 0;
	current = *stack_b;
	highest_index = current->index;
	i++;
	while (i <= size)
	{
		i++;
		current = current->next;
		if (current->index > highest_index)
		{
			highest_index = current->index;
			position = i;
		}
	}
	while (position <= size / 2 && position > 0)
		ft_highest_app(stack_b, &position, 0);
	while (position > size / 2 && position <= size)
		ft_highest_app(stack_b, &position, 1);
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
