/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmezzaba <lmezzaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:00:00 by lmezzaba          #+#    #+#             */
/*   Updated: 2026/06/02 14:13:57 by lmezzaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char sep)
{
	int	i;
	int	count;

	if (!str || !str[0])
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *str, char sep, int i)
{
	int	len;

	len = 0;
	while (str[i] == sep)
		i++;
	while (str[i] && str[i] != sep)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_fill_word(char const *str, char sep, int *s)
{
	int		i;
	char	*word;

	i = 0;
	while (str[*s] && str[*s] == sep)
		(*s)++;
	word = malloc(ft_wordlen(str, sep, *s) + 1);
	if (!word)
		return (0);
	while (str[*s] && str[*s] != sep)
		word[i++] = str[(*s)++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char charset)
{
	int		s;
	int		i;
	char	**tab_str;

	if (!str)
		return (0);
	tab_str = malloc(sizeof(char *) * (ft_wordcount(str, charset) + 1));
	if (!tab_str)
		return (0);
	s = 0;
	i = 0;
	while (i < ft_wordcount(str, charset))
	{
		tab_str[i] = ft_fill_word(str, charset, &s);
		if (!tab_str[i])
			return (ft_free_split(tab_str, i));
		i++;
	}
	tab_str[i] = 0;
	return (tab_str);
}
