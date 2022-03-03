/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:33:26 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 15:09:19 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	retrace_map(t_info *info)
{
	mlx_destroy_image(info->mlx,  info->img.img);
	info->img.img = mlx_new_image(info->mlx, 1920, 1080);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel, &info->img.line_length, &info->img.endian);
	print_point(info);
}

int	hook(int keycode, t_info *info)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		closewin(info);
	if (keycode == 65361)
		gauche(info);
	if (keycode == 65363)
		droite(info);
	if (keycode == 65362)
		haut(info);
	if (keycode == 65364)
		bas(info);
	if (keycode == 114)
		reset(info);
	if (keycode == 119 && info->projection == 0)
		rota_up(info);
	if (keycode == 97 && info->projection == 0)
		rota_left(info);
	if (keycode == 115 && info->projection == 0)
		rota_down(info);
	if (keycode == 100 && info->projection == 0)
		rota_right(info);
	if (keycode == 65451)
		zoom_in(info);
	if (keycode == 65453)
		zoom_out(info);
	if (keycode == 104)
		high(info);
	if (keycode == 108)
		low(info);
	if (keycode == 112)
		projection(info);
	if (keycode == 99)
		color(info);
	return (0);
}
