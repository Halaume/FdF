/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:54:54 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 17:15:31 by ghanquer         ###   ########.fr       */
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
		while (info->tab_point[i])
		{
			free(info->tab_point[i]);
			i++;
		}
	}
	free(info->tab_point);
}

void	free_fun(t_info *info)
{
	free_list(info);
	exit (0);
}
