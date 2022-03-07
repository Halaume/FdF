/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:56:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/06 14:26:59 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	norme_moi2(int x, int y, int diff, t_info *info)
{
	my_mlx_pixel_put(&info->img, x + WIDTH / 2 * info->zoom, \
			y + HEIGHT / 2 * info->zoom, info->color);
	if (diff < 0)
		diff++;
	else
		diff--;
	return (diff);
}

void	norme_moi(t_info *info, t_point p1, t_point p2, int choose)
{
	int	diff;
	int	x;
	int	y;

	if (choose == 1)
	{
		diff = p2.x - p1.x;
		while (diff)
		{
			x = p1.x + diff;
			y = (int)round(((x - p1.x) / (p2.x - p1.x)) * (p2.y - p1.y) + p1.y);
			diff = norme_moi2(x, y, diff, info);
		}
	}
	else
	{
		diff = p2.y - p1.y;
		while (diff)
		{
			y = p1.y + diff;
			x = (int)round(((y - p1.y) / (p2.y - p1.y)) * (p2.x - p1.x) + p1.x);
			diff = norme_moi2(x, y, diff, info);
		}
	}
}

void	bricenham(t_info *info, t_point point1, t_point point2)
{
	(void)info;
	if ((info->colorbool == 1 && \
				(point1.z > info->mid.z || point2.z > info->mid.z)))
		info->color = 0x00FF0F0F;
	else if (info->colorbool == 1 && (point1.z < info->mid.z || \
				point2.z < info->mid.z))
		info->color = 0x00FF0FF0;
	else
		info->color = 0x00FFFFFF;
	if (fabs(point2.x - point1.x) > fabs(point2.y - point1.y))
		norme_moi(info, point1, point2, 1);
	else
		norme_moi(info, point1, point2, 2);
	my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, \
			point1.y + HEIGHT / 2 * info->zoom, info->color);
}
