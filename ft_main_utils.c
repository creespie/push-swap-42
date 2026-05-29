/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_order_array(t_stack *a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = a->index;
		a = a->next;
		i++;
	}
}

static void	ft_count_disorder(t_disorder *data, int *arr, int size)
{
	data->i = 0;
	data->mistakes = 0;
	data->total = 0;
	while (data->i < size)
	{
		data->j = data->i + 1;
		while (data->j < size)
		{
			data->total++;
			if (arr[data->i] > arr[data->j])
				data->mistakes++;
			data->j++;
		}
		data->i++;
	}
}

double	ft_compute_disorder(t_stack *a, int size)
{
	int			*arr;
	t_disorder	data;
	double		result;

	if (size <= 1)
		return (0.0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0.0);
	ft_fill_order_array(a, arr, size);
	ft_count_disorder(&data, arr, size);
	result = (double)data.mistakes / (double)data.total;
	free(arr);
	return (result);
}

void	ft_link_bench(t_stack *a, int size, t_bench *bench)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a->bench = bench;
		a = a->next;
		i++;
	}
}

void	ft_main_sort(t_app *app)
{
	if (app->argc - 1 <= 4)
		ft_sort_few(&app->a, &app->b, app->argc - 1);
	else if (app->strategy == FLAG_SIMPLE)
		ft_ins_sort(&app->a, &app->b);
	else if (app->strategy == FLAG_MEDIUM)
		ft_chunk_sort(&app->a, &app->b);
	else if (app->strategy == FLAG_COMPLEX)
		ft_radix_sort(&app->a, &app->b);
	else if (app->disorder < 0.2)
		ft_ins_sort(&app->a, &app->b);
	else if (app->disorder < 0.5)
		ft_chunk_sort(&app->a, &app->b);
	else
		ft_radix_sort(&app->a, &app->b);
}
