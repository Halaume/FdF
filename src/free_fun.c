/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:54:54 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/23 11:31:42 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_tab_point(t_info *info)
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
		free(info->tab_point);
	}
}
