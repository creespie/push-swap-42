#include "push_swap.h"

void	ft_convert_stack(int *arr, t_stack **stack_a, int size)
{
	int	i;
	t_stack *new;

	i = 0;
	while (size > 0)
	{
		new = ft_lstnew_adapt(arr[i]);
		if (*stack_a == NULL)
			*stack_a = new;
		else
			ft_lstadd_back_adapt(stack_a, new);
		i++;
		size--;
	}
	ft_close_circle(*stack_a);
}

void	ft_close_circle(t_stack *stack_a)
{
	t_stack	*first;
	t_stack	*last;

	first = stack_a;
	last = ft_lstlast_adapt(stack_a);
	first->prev = last;
	last->next = first;
}
