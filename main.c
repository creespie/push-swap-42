#include "push_swap.h"

static void	ft_main_app(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc - 1 <= 4)
		ft_sort_few(stack_a, stack_b, argc - 1);
	else
		ft_sort_everything(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int	*arr;
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_errors(argc, argv) == 0)
		return (0);
	arr = malloc((argc - 1) * sizeof(int));
	if (ft_array_handling(argc, argv, arr, &stack_a) == 0)
		return (0);
	if (ft_check_order(stack_a, argc - 1) == 1)
	{}
	else
		ft_main_app(argc, &stack_a, &stack_b);
	ft_free_stack(&stack_a, ft_lst_count(stack_a));
	free(arr);
	return (0);
}
