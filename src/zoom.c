/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:02:46 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/07 12:27:13 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom_in(t_info *info)
{
	info->spacing *= 1.2;
	retrace_map(info);
}

void	zoom_out(t_info *info)
{
	info->spacing *= 0.8;
	retrace_map(info);
}

void	high(t_info *info)
{
	info->epaisseur--;
	if (info->epaisseur <= 0)
		info->epaisseur = 1;
	retrace_map(info);
}

void	low(t_info *info)
{
	info->epaisseur++;
	retrace_map(info);
}

void	color(t_info *info)
{
	double	tmp;

	if (info->colorbool == 0)
		info->colorbool = 1;
	else if (info->colorbool == 1)
	{
		info->colorbool = 2;
		tmp = info->mid.z;
		info->mid.z = info->save_z;
		info->save_z = tmp;
	}
	else
	{
		info->colorbool = 0;
		tmp = info->mid.z;
		info->mid.z = info->save_z;
		info->save_z = tmp;
	}
	retrace_map(info);
}
