#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*arr;
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
		{
			write (2, "Error\n", 6);
			return(0);
		}
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write (2, "Error\n", 6);
				return(0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	arr = malloc((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (ft_check_double(arr, argc - 1) == 0)
	{
		write (2, "Error\n", 6);
		free(arr);
		return(0);
	}
	ft_convert_stack(arr, &stack_a, argc - 1);
	ft_sort_arr(arr, argc - 1);
	ft_add_order(arr, stack_a, argc-1);
	if (ft_check_order(stack_a, argc - 1) == 1)
	{}
	else
	{
		if (argc - 1 <= 4)
			ft_sort_few(&stack_a, &stack_b, argc - 1);
		else
			ft_sort_everything(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a, ft_lst_count(stack_a));
	ft_free_stack(&stack_b, ft_lst_count(stack_b));
	free(arr);
	return (0);
}
