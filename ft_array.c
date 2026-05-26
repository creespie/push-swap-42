#include "push_swap.h"
#include "libft.h"
void	ft_sort_arr(int *arr, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
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

/*
** Assigns each node in stack_a its sorted rank (index),
** using the sorted copy of the array.
*/
void	ft_add_order(int *arr, t_stack *stack_a, int size)
{
	t_stack	*temp;
	int		i;

	temp = stack_a;
	if (!stack_a)
		return ;
	while (size > 0)
	{
		i = 0;
		while (arr[i] != temp->content)
			i++;
		temp->index = i;
		temp = temp->next;
		size--;
	}
}

void	ft_convert_stack(int *arr, t_stack **stack_a, int size)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (size > 0)
	{
		new = ft_lstnew_ps(arr[i]);
		if (!new)
			return ;
		if (*stack_a == NULL)
			*stack_a = new;
		else
			ft_lstadd_back_ps(stack_a, new);
		i++;
		size--;
	}
	ft_close_circle(*stack_a);
}

int	ft_array_handling(int argc, char *argv[], int *arr, t_stack **stack_a)
{
	int		i;
	int		*sorted;

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_atoi_safe(argv[i + 1], &arr[i]))
		{
			return (ft_write_err());
		}
		
		i++;
	}
	if (ft_check_double(arr, argc - 1) == 0)
		return (ft_write_err());
	ft_convert_stack(arr, stack_a, argc - 1);
	sorted = malloc((argc - 1) * sizeof(int));
	if (!sorted)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		sorted[i] = arr[i];
		i++;
	}
	ft_sort_arr(sorted, argc - 1);
	ft_add_order(sorted, *stack_a, argc - 1);
	free(sorted);
	return (1);
}
