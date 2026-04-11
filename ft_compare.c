#include "push_swap.h"

void	ft_compare_append(int pos, int spot, int *total)
{
	if ((pos > 0 && pos > spot) || (pos < 0 && pos < spot))
		(*total) = pos;
	else
		(*total) = spot;
}

void	ft_compare_two(int pos_2, int spot_2, int *total_2)
{
	if ((pos_2 > 0 && pos_2 > spot_2) || (pos_2 < 0 && pos_2 < spot_2))
		(*total_2) = pos_2;
	else
		(*total_2) = spot_2;
}

int	ft_compare(int	pos, int spot, int	pos_2, int spot_2)
{
	int	total;
	int	total_2;

	if ((pos > 0 && spot > 0)|| (pos < 0 && spot < 0))
		ft_compare_append(pos,spot, &total);
	else
		total = (spot * -1) + pos;
	if ((pos_2 > 0 && spot_2 > 0)|| (pos_2 < 0 && spot_2 < 0))
		ft_compare_two(pos_2, spot_2, &total_2);
	else
		total_2 = (spot_2 * -1) + pos_2;
	if (total < 0)
		total *= -1;
	if (total_2 < 0)
		total_2 *= -1;
	if (total_2 < total)
		return 1;
	return 0;
}
