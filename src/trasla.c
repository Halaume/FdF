/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:38:44 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 13:05:59 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


void	gauche(t_info *info)
{
	info->xval -= 5;
	retrace_map(info);
}

void	droite(t_info *info)
{
	info->xval += 5;
	retrace_map(info);
}

void	haut(t_info *info)
{
	info->yval -= 5;
	retrace_map(info);
}

void	bas(t_info *info)
{
	info->yval += 5;
	retrace_map(info);
}

void	reset(t_info *info)
{
	info->tab_point = info->save;
	info->zoom = 1;
	get_spacing(info);
	info->color = 0x00FFFFFF;
	info->epaisseur = 1;
	info->angle_y = 0;
	info->angle_z = M_PI / 4;
	info->angle_x = M_PI / 2 - atan(M_PI / 6);
	info->xval = 0;
	info->yval = 0;
	info->projection = 0;
	retrace_map(info);
}
