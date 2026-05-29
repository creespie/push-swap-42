#include "push_swap.h"


void	ft_sa(t_stack **stack_a, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		tmp;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;

	n1 = *stack_a;
	n2 = n1->next;

	tmp = n1->content;
	n1->content = n2->content;
	n2->content = tmp;

	tmp = n1->index;
	n1->index = n2->index;
	n2->index = tmp;

	if (flag == 1)
		write(1, "sa\n", 3);
	ft_bench_update(*stack_a,OP_SA);
}

void	ft_sb(t_stack **stack_b, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		tmp;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return;

	n1 = *stack_b;
	n2 = n1->next;

	tmp = n1->content;
	n1->content = n2->content;
	n2->content = tmp;

	tmp = n1->index;
	n1->index = n2->index;
	n2->index = tmp;

	if (flag == 1)
		write(1, "sb\n", 3);
	ft_bench_update(*stack_b,OP_SB);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int flag)
{

	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);


	if (flag == 1)
		write(1, "ss\n", 3);
	ft_bench_update(*stack_a,OP_SS);
}