/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:56:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/02 18:37:16 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	bricenham(t_info *info, t_point point1, t_point point2)
{
	int	x;
	int	y;
	int	diff;

	(void)info;
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

/*void	bresenham(t_info *info, t_point point1, t_point point2)
{
	int	dx;
	int	dy;
	int	e;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.x != point2.x)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e - dy;
							if (e < 0)
							{
								point1.y++;
								e = e + dx;
							}
							point1.x++;
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (point1.y != point2.y)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e - dx;
							if (e < 0)
							{
								point1.x++;
								e = e + dy;
							}
							point1.y++;
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.x != point2.x)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e + dy;
							if (e < 0)
							{
								point1.y--;
								e = e + dx;
							}
							point1.x++;
						}
					}
					else
					{
						e = dy;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.y != point2.y)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e + dx;
							if (e > 0)
							{
								point1.x--;
								e = e + dy;
							}
							point1.y--;
						}
					}
				}
			}
			else
			{
				while (point1.x != point2.x)
				{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
					point1.x++;
				}
			}
		}
		else
		{
			dy = point2.y - point1.y;
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.x != point2.x)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e + dy;
							if (e >= 0)
							{
								point1.y++;
								e = e + dx;
							}
							point1.x--;
						}
					}
					else
					{
						e = dy;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.y != point2.y)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e + dx;
							if (e <= 0)
							{
								point1.x--;
								e = e + dy;
							}
							point1.y++;
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.x != point2.x)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e - dy;
							if (e >= 0)
							{
								point1.y--;
								e = e + dx;
							}
							point1.x--;
						}
					}
					else
					{
						e = dy;
						dx = dx * 2;
						dy = dy * 2;
						while (point1.y != point2.y)
						{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
							e = e - dx;
							if (e >= 0)
							{
								point1.x--;
								e = e + dy;
							}
							point1.y--;
						}
					}
				}
			}
			else
			{
				while (point1.x != point2.x)
				{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
					point1.x--;
				}
			}
		}
	}
	else
	{
		dy = point2.y - point1.y;
		if (dy != 0)
		{
			if (dy > 0)
			{
				while (point1.y != point2.y)
				{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
					point1.y++;
				}
			}
			else
			{
				while (point1.y != point2.y)
				{
							my_mlx_pixel_put(&info->img, point1.x + WIDTH / 2 * info->zoom, point1.y + HEIGHT / 2 * info->zoom, info->color);
					point1.y--;
				}
			}
		}
	}
}*/