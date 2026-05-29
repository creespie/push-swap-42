/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_strategy(t_bench *b)
{
	ft_write_str("strategy: ");
	if (b->strategy == FLAG_SIMPLE)
		ft_write_str("simple / O(n^2)\n");
	else if (b->strategy == FLAG_MEDIUM)
		ft_write_str("medium / O(n sqrt(n))\n");
	else if (b->strategy == FLAG_COMPLEX)
		ft_write_str("complex / O(n log n)\n");
	else if (b->disorder < 0.2)
		ft_write_str("adaptive-simple / O(n^2)\n");
	else if (b->disorder < 0.5)
		ft_write_str("adaptive-medium / O(n sqrt(n))\n");
	else
		ft_write_str("adaptive-complex / O(n log n)\n");
}

static void	ft_print_swap_push(t_bench *b)
{
	ft_write_str("sa: ");
	ft_write_int(b->sa);
	ft_write_str(" sb: ");
	ft_write_int(b->sb);
	ft_write_str(" ss: ");
	ft_write_int(b->ss);
	ft_write_str(" pa: ");
	ft_write_int(b->pa);
	ft_write_str(" pb: ");
	ft_write_int(b->pb);
	ft_write_str("\n");
}

static void	ft_print_rotate(t_bench *b)
{
	ft_write_str("ra: ");
	ft_write_int(b->ra);
	ft_write_str(" rb: ");
	ft_write_int(b->rb);
	ft_write_str(" rr: ");
	ft_write_int(b->rr);
	ft_write_str(" rra: ");
	ft_write_int(b->rra);
	ft_write_str(" rrb: ");
	ft_write_int(b->rrb);
	ft_write_str(" rrr: ");
	ft_write_int(b->rrr);
	ft_write_str("\n");
}

void	ft_print_bench(t_bench *b)
{
	if (!b || !b->enabled)
		return ;
	ft_write_str("[bench] disorder: ");
	ft_write_percent(b->disorder);
	ft_write_str("%\n[bench] ");
	ft_print_strategy(b);
	ft_write_str("[bench] total_ops: ");
	ft_write_int(b->total_ops);
	ft_write_str("\n[bench] ");
	ft_print_swap_push(b);
	ft_write_str("[bench] ");
	ft_print_rotate(b);
}
