#include "push_swap.h"

/*
** Starts the main sort, choosing sort few for 4 or less arguments
** or the other selected sorting system, ft_ins_sort() for simple
** insertion sort, ft_chunk_sort() for medium chunk sort or 
** ft_sort_everything() for the complex optimized sort. all passed
** with (stack_a, stack_b) as argument
*/

static void	ft_main_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc - 1 <= 4)
		ft_sort_few(stack_a, stack_b, argc - 1);
	else
		ft_ins_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_errors(argc, argv) == 0)
		return (0);
	arr = malloc((argc - 1) * sizeof(int));
	if (!arr)
		return (0);
	if (ft_array_handling(argc, argv, arr, &stack_a) == 0)
	{
		free(arr);
		return (0);
	}
	free(arr);
	if (ft_check_order(stack_a, argc - 1) == 0)
		ft_main_sort(argc, &stack_a, &stack_b);
	ft_free_stack(&stack_a, ft_lst_count(stack_a));
	if (stack_b)
		ft_free_stack(&stack_b, ft_lst_count(stack_b));
	return (0);
}
