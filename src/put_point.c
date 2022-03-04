/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:04:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/04 18:05:42 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	print_point(t_info *info)
{
	int		x;
	int		y;
	int		line;
	t_point	point;

	x = 0;
	while (x < info->nbline)
	{
		y = 0;
		while (y < info->nbcol)
		{
			line = 0;
			if (info->colorbool == 1 && info->tab_point[x][y].z > info->mid.z)
				info->color = 0x00FF0F0F;
			else if (info->colorbool == 1 && \
					info->tab_point[x][y].z < info->mid.z)
				info->color = 0x00FF0FF0;
			else if (info->colorbool == 1)
				info->color = 0x00FFFFFF;
			point = rota(info, info->tab_point[x][y]);
			my_mlx_pixel_put(&info->img, point.x + WIDTH / 2 * info->zoom, \
					point.y + HEIGHT / 2 * info->zoom, info->color);
			if (x + 1 < info->nbline)
				bricenham(info, point, rota(info, info->tab_point[x + 1][y]));
			if (y + 1 < info->nbcol)
				bricenham(info, point, rota(info, info->tab_point[x][y + 1]));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->window, info->img.img, 0, 0);
}

void	get_tab_point(t_info *info)
{
	int			i;
	int			j;
	char		*nocolorcode;
	char		**splitmap;
	t_map_list	*tmp_map;

	j = 0;
	tmp_map = info->map;
	alloctab_point(info);
	get_spacing(info);
	while (tmp_map)
	{
		i = 0;
		splitmap = ft_split(tmp_map->line, ' ');
		while (splitmap[i])
		{
			nocolorcode = get_no_color(splitmap[i]);
			if (nocolorcode == NULL)
			{
				free_map(splitmap);
				free_fun(info);
			}
			info->tab_point[j][i].x = i - info->nbline / 2;
			info->tab_point[j][i].y = j - info->nbcol / 2;
			info->tab_point[j][i].z = ft_atoi(nocolorcode);
			free(nocolorcode);
			i++;
		}
		j++;
		tmp_map = tmp_map->next;
		free_map(splitmap);
	}
	info->save = info->tab_point;
	info->nbline = j;
	info->nbcol = i;
	get_mid(info);
}
