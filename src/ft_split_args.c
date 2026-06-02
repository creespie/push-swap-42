/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/06/02 14:42:10 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	ft_count_args(int argc, char **argv)
{
	char	**tmp;
	int		i;
	int		total;

	i = 1;
	total = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp || !tmp[0])
		{
			ft_free_tmp(tmp);
			return (0);
		}
		total += ft_tab_size(tmp);
		ft_free_tmp(tmp);
		i++;
	}
	return (total);
}

static int	ft_fill_args(int argc, char **argv, char **out)
{
	int		i;
	int		k;

	i = 1;
	k = 1;
	while (i < argc)
	{
		k = ft_copy_split(argv[i], out, k);
		if (k == -1)
			return (-1);
		i++;
	}
	out[k] = NULL;
	return (k);
}

char	**ft_split_args(int argc, char **argv, int *new_argc)
{
	char	**out;
	int		total;

	total = ft_count_args(argc, argv);
	if (total == 0)
		return (NULL);
	out = malloc(sizeof(char *) * (total + 1));
	if (!out)
		return (NULL);
	out[0] = argv[0];
	*new_argc = ft_fill_args(argc, argv, out);
	if (*new_argc == -1)
		return (ft_free_split_args(out), NULL);
	return (out);
}
