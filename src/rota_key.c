/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:07:00 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 16:31:51 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	projection(t_info *info)
{
	if (info->projection == 0)
	{
		info->angle_y = 0;
		info->angle_z = 0;
		info->angle_x = 0;
		info->projection = 1;
	}
	else
	{
		info->angle_y = 0;
		info->angle_z = M_PI / 4;
		info->angle_x = M_PI / 2 - atan(M_PI / 6);
		info->projection = 0;
	}
	retrace_map(info);
}
void	rota_up(t_info *info)
{
	info->angle_x += 0.1;
	retrace_map(info);
}

void	rota_left(t_info *info)
{
	info->angle_z += 0.1;
	retrace_map(info);
}

void	rota_down(t_info *info)
{
	info->angle_x -= 0.1;
	retrace_map(info);
}

void	rota_right(t_info *info)
{
	info->angle_z -= 0.1;
	retrace_map(info);
}
