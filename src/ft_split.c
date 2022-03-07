/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:27:03 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/07 19:48:06 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static char	**free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	nb_word(char *str, char c)
{
	int		count;
	int		i;
	char	*s;

	if (!str[0])
		return (0);
	s = ft_strtrim(str, "\n");
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	free(s);
	return (count);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_len, char c)
{
	unsigned int	i;

	*next_str += *next_len;
	*next_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned long	i;

	i = 0;
	if (n != 0)
	{
		while (src[i] && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char				**tab;
	char				*next_str;
	unsigned int		nbword;
	unsigned int		next_len;
	unsigned int		i;

	i = 0;
	nbword = nb_word(s, c);
	next_str = (char *) s;
	next_len = 0;
	tab = malloc(sizeof(char *) * (nbword + 1));
	if (!tab)
		return (NULL);
	while (i < nbword)
	{
		ft_get_next_str(&next_str, &next_len, c);
		if (!next_len)
			return (tab);
		tab[i] = malloc(sizeof(char) * next_len + 1);
		if (!tab[i])
			return (free_tab(tab));
		ft_strlcpy(tab[i++], next_str, next_len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
