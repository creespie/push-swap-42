#include "push_swap.h"

int	ft_convert_stack(int *arr, t_list **stack_a)
{
	int	i;
	t_list *new;

	i = 0;
	while (arr[i])
	{
		*new = *ft_lstnew(arr[i]);
		ft_lstadd_back(*stack_a, new);
		i++;
	}
	return (i);
}