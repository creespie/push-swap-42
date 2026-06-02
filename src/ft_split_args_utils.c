/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:13:48 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/06/02 14:19:40 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tmp(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_split_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	ft_copy_split(char *arg, char **out, int k)
{
	char	**tmp;
	int		j;

	tmp = ft_split(arg, ' ');
	if (!tmp)
		return (-1);
	j = 0;
	while (tmp[j])
		out[k++] = tmp[j++];
	free(tmp);
	return (k);
}
