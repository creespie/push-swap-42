/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/05/29 12:00:00 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_flag(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_flag(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strcmp_flag(arg, "--bench") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp_flag(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

static void	ft_shift_args(char *argv[], int i, int argc)
{
	while (i < argc - 1)
	{
		argv[i] = argv[i + 1];
		i++;
	}
}

int	ft_remove_flags(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_flag(argv[i]))
		{
			ft_shift_args(argv, i, argc);
			argc--;
			i--;
		}
		i++;
	}
	return (argc);
}

void	ft_flag_checker(char *flag, int *strategy, int *numbers_flags)
{
	(*numbers_flags)++;
	if (ft_strcmp_flag(flag, "--simple") == 0)
		*strategy = FLAG_SIMPLE;
	else if (ft_strcmp_flag(flag, "--medium") == 0)
		*strategy = FLAG_MEDIUM;
	else if (ft_strcmp_flag(flag, "--complex") == 0)
		*strategy = FLAG_COMPLEX;
	else if (ft_strcmp_flag(flag, "--adaptive") == 0)
		*strategy = FLAG_ADAPTIVE;
}

/*remove || *numbers_flags is bench can be the second flag*/
int	ft_parse_helper(t_bench *bench, char *str, int *numbers_flags, int *strategy)
{
	if (ft_strcmp_flag(str, "--bench") == 0)
		if (bench->enabled == 1)
			return(-1);
		else
		{
			bench->enabled = 1;
			return (0);
		}
	else if (ft_strcmp_flag(str, "--simple") == 0
			|| ft_strcmp_flag(str, "--medium") == 0
			|| ft_strcmp_flag(str, "--complex") == 0
			|| ft_strcmp_flag(str, "--adaptive") == 0)
		if (*numbers_flags)
			return (-1);
		else
		{
			ft_flag_checker(str, strategy, numbers_flags);
			return (0);
		}
	else
		return (1);
}

int	ft_parse_flags(int argc, char *argv[], int *strategy, t_bench *bench)
{
	int	i;
	int	numbers_flags;
	int	outcome;

	numbers_flags = 0;
	i = 1;
	*strategy = FLAG_ADAPTIVE;
	while (i < argc)
	{
		outcome = ft_parse_helper(bench, argv[i], &numbers_flags, strategy);
		if (outcome == -1)
			return(-1);
		else if (outcome == 1)
			numbers_flags++;
		i++;
	}
	return (0);
}
