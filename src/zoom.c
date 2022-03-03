/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:02:46 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 12:22:45 by ghanquer         ###   ########.fr       */
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
