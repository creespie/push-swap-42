/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cost_same_dir(int pos, int spot)
{
	if ((pos > spot && pos > 0) || (pos < spot && pos < 0))
		return (pos);
	return (spot);
}

static int	ft_cost_opp_dir(int pos, int spot)
{
	if (pos < 0)
		pos *= -1;
	if (spot < 0)
		spot *= -1;
	return (pos + spot);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_compare(int pos, int spot, int pos_2, int spot_2)
{
	int	total;
	int	total_2;

	if ((pos >= 0 && spot >= 0) || (pos <= 0 && spot <= 0))
		total = ft_abs(ft_cost_same_dir(pos, spot));
	else
		total = ft_cost_opp_dir(pos, spot);
	if ((pos_2 >= 0 && spot_2 >= 0) || (pos_2 <= 0 && spot_2 <= 0))
		total_2 = ft_abs(ft_cost_same_dir(pos_2, spot_2));
	else
		total_2 = ft_cost_opp_dir(pos_2, spot_2);
	if (total_2 < total)
		return (1);
	return (0);
}
