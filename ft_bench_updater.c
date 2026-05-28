#include "push_swap.h"


void	ft_bench_update(t_stack *stack, enum e_op op)
{
	t_bench	*b;

	if (!stack)
		return;

	b = stack->bench;
	if (!b || !b->enabled)
		return;

	b->total_ops++;

	if (op == OP_SA)
		b->sa++;
	else if (op == OP_SB)
		b->sb++;
	else if (op == OP_SS)
		b->ss++;
	else if (op == OP_PA)
		b->pa++;
	else if (op == OP_PB)
		b->pb++;
	else if (op == OP_RA)
		b->ra++;
	else if (op == OP_RB)
		b->rb++;
	else if (op == OP_RR)
		b->rr++;
	else if (op == OP_RRA)
		b->rra++;
	else if (op == OP_RRB)
		b->rrb++;
	else if (op == OP_RRR)
		b->rrr++;
}