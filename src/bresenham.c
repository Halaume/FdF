/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:56:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 19:07:25 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

//void	bricenham2(t_info *info, t_point point1, t_point point2)
//{
//}

void	bricenham(t_info *info, t_point point1, t_point point2)
{
	int	x;
	int	y;
	int	diff;

	(void)info;
	if (info->colorbool == 1 && (point1.z > info->mid.z || point2.z > info->mid.z))
		info->color = 0x00FF0F0F;
	else if (info->colorbool == 1 && (point1.z < info->mid.z || point2.z < info->mid.z))
		info->color = 0x00FF0FF0;
	else if (info->colorbool == 1)
		info->color = 0x00FFFFFF;
	if (abs(point2.x - point1.x) > abs(point2.y - point1.y))
	{
		diff = point2.x - point1.x;
		while (diff)
		{
			x = point1.x + diff;
			y = (int)round(((double)(x - point1.x) / (double)(point2.x - point1.x)) * (double)(point2.y - point1.y) + (double)point1.y);
			my_mlx_pixel_put(&info->img, x + WIDTH / 2 * info->zoom, y + HEIGHT / 2 * info->zoom, info->color);
			if (diff < 0)
				diff++;
			else
				diff--;
		}
	}
	else
	{
//		bricenham2(info, point1, point2);
		diff = point2.y - point1.y;
		while (diff)
		{
			y = point1.y + diff;
			x = (int)round(((double)(y - point1.y) / (double)(point2.y - point1.y)) * (double)(point2.x - point1.x) + (double)point1.x);
			my_mlx_pixel_put(&info->img, x + WIDTH / 2 * info->zoom, y + HEIGHT / 2 * info->zoom, info->color);
			if (diff < 0)
				diff++;
			else
				diff--;
		}
	}
	my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
}
