/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:50:39 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/23 11:52:20 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (s[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	neg = 1;
	i = 0;
	res = 0;
	while (str[i] == '0' || (str[i] < 14 && str[i] > 8) || str [i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int	size_of_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	size_of_col(t_info *info)
{
	int			i;
	t_map_list	*tmp;

	tmp = info->map;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	alloctab_point(t_info *info)
{
	int		nbline;
	int		nbcol;
	char	**tmp;

	tmp = ft_split(info->map->line, ' ');
	nbline = size_of_line(tmp);
	nbcol = size_of_col(info);
	info->tab_point = malloc(sizeof(t_point *) * nbcol);
	*info->tab_point = malloc(sizeof(t_point) * nbline);
}
