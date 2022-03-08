/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:04:11 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/07 12:27:37 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	print_point2(t_info *info, int x, t_point point)
{
	int	y;

	y = 0;
	while (y < info->nbcol)
	{
		if ((info->colorbool > 0 && \
					info->tab_point[x][y].z > info->mid.z))
			info->color = 0x00FF0F0F;
		else if (info->colorbool > 0 && \
				info->tab_point[x][y].z < info->mid.z)
			info->color = 0x00FF0FF0;
		else
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
}

void	print_point(t_info *info)
{
	int		x;
	t_point	point;

	x = 0;
	point = info->tab_point[0][0];
	while (x < info->nbline)
	{
		print_point2(info, x, point);
		x++;
	}
	mlx_put_image_to_window(info->mlx, info->window, info->img.img, 0, 0);
}

int	get_tab_point2(t_info *info, t_map_list *tmp_map, int j)
{
	int		i;
	char	*nocolorcode;
	char	**splitmap;

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
		info->save_z += ft_atoi(nocolorcode);
		if (nocolorcoe[0] != '\0')
			free(nocolorcode);
		i++;
	}
	free_map(splitmap);
	return (i);
}

void	get_tab_point(t_info *info)
{
	int			i;
	int			j;
	t_map_list	*tmp_map;

	j = 0;
	tmp_map = info->map;
	alloctab_point(info);
	get_spacing(info);
	while (tmp_map)
	{
		i = get_tab_point2(info, tmp_map, j);
		j++;
		tmp_map = tmp_map->next;
	}
	info->save = info->tab_point;
	info->nbline = j;
	info->nbcol = i;
	info->save_z = info->save_z / (i * j);
	get_mid(info);
}
