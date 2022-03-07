/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:46:43 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/07 19:47:22 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_isinstr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = ft_strlen(s1);
	j = 0;
	k = 0;
	while (i > 0 && ft_isinstr(set, s1[i - 1]))
		i--;
	while (j < i && s1[j] && ft_isinstr(set, s1[j]))
		j++;
	dest = malloc(sizeof(char) * (i - j) + 1);
	if (!dest)
		return (NULL);
	while (j < i)
		dest[k++] = s1[j++];
	dest[k] = '\0';
	return (dest);
}
