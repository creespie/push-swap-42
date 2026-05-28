#include "push_swap.h"

/*
** Swaps content and index of the top two nodes
** (avoids pointer surgery on a circular list).
*/
void	ft_sa(t_stack **stack_a, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		tmp;
	t_bench	*b;

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

	b = n1->bench;
	if (b && b->enabled)
	{
		b->total_ops++;
		b->sa++;
	}

	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int flag)
{
	t_stack	*n1;
	t_stack	*n2;
	int		tmp;
	t_bench	*b;

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

	b = n1->bench;
	if (b && b->enabled)
	{
		b->total_ops++;
		b->sb++;
	}

	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_bench	*b;

	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);

	if (stack_a && *stack_a)
	{
		b = (*stack_a)->bench;
		if (b && b->enabled)
		{
			b->total_ops++;
			b->ss++;
		}
	}

	write(1, "ss\n", 3);
}