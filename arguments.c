#include "push_swap.h"

int	ft_convert_stack(int *arr, t_list **stack_a)
{
	int	i;
	t_list *new;

	i = 0;
	while (arr[i])
	{
		new = ft_lstnew(arr[i]);
		ft_lstadd_back(*stack_a, new);
		i++;
	}
	return (i);
}

void	ft_sort_arr(int *arr)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	temp = 0;
	while (arr[i])
	{
		y = i;
		while (arr[y])
		{
			if (arr[y] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[y];
				arr[y] = temp;
			}
			y++;
		}
		i++;
	}
}

void	ft_add_order(int *arr, t_list *stack_a)
{
	int	i;

	if (stack_a == NULL)
		return ;
	while (stack_a != NULL)
	{
		i = 0;
		while (arr[i] != stack_a->content)
			i++;
		stack_a->order = i;
		stack_a = stack_a->next;
	}
}
