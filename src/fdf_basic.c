/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:16:54 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 16:32:36 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_info(t_info *info)
{
	info->mlx = NULL;
	info->window = NULL;
	info->tab_point = NULL;
	info->zoom = 1;
	info->map = NULL;
	info->spacing = 0;
	info->color = 0x00FFFFFF;
	info->epaisseur = 1;
	info->angle_y = 0;
	info->angle_z = M_PI / 4;
	info->angle_x = M_PI / 2 - atan(M_PI / 6);
	info->xval = 0;
	info->yval = 0;
	info->colorbool = 0;
	info->projection = 0;
}

void	get_spacing(t_info *info)
{
	info->spacing = HEIGHT / info->nbcol;
	if (info->spacing > HEIGHT / info->nbline)
		info->spacing = HEIGHT / info->nbline;
	if (info->spacing > WIDTH / info->nbline)
		info->spacing = WIDTH / info->nbline;
	if (info->spacing > WIDTH / info->nbcol)
		info->spacing = WIDTH / info->nbcol;
}

void	get_mid(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->tab_point[i][j].x != 0)
		j++;
	while (info->tab_point[i][j].y != 0)
		i++;
	info->mid.z = info->tab_point[i][j].z;
	info->mid.x = info->tab_point[i][j].x;
	info->mid.y = info->tab_point[i][j].y;
	printf("\nx = %d y = %d z = %d\n", info->mid.x, info->mid.y, info->mid.z);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	closewin(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->window);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free_fun(info);
	exit (0);
	return (1);
}
