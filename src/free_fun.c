/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:54:54 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/04 17:28:49 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(char **splitmap)
{
	int	i;

	i = 0;
	if (splitmap)
	{
		while (splitmap[i])
		{
			free(splitmap[i]);
			i++;
		}
		free(splitmap);
	}
}

void	free_list(t_info *info)
{
	int	i;

	i = 0;
	if (info->tab_point)
	{
		while (i < info->freetab)
		{
			free(info->tab_point[i]);
			i++;
		}
	}
	free(info->tab_point);
}

void free_lst_map(t_info *info)
{
	t_map_list	*tmp;

	if(info->map)
	{
		while (info->map)
		{
			tmp = info->map;
			info->map = info->map->next;
			free(tmp->line);
			free(tmp);
		}
	}
}

void	free_fun(t_info *info)
{
	free_list(info);
	free_lst_map(info);
	exit (0);
}
