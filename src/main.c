/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/02 18:33:16 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	dist(t_point mid, t_point point)
{
	int		dist;
	t_point	final_point;

	dist = sqrt((pow((mid.x - point.x), 2)) + (pow((mid.y - point.y), 2)) + (pow((mid.z - point.z), 2)));
	if (point.x >= 0)
		final_point.x = point.x - dist;
	if (point.x <= 0)
		final_point.x = point.x + dist;
	if (point.y <= 0)
		final_point.y = point.y + dist;
	if (point.y >= 0)
		final_point.y = point.y - dist;
	final_point.z = point.z;
	return (final_point);
}

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
			if (info->tab_point[x][y].z > info->mid.z)
				info->color = 0x00FF0F0F;
			else if (info->tab_point[x][y].z < info->mid.z)
				info->color = 0x00FF0FF0;
			else
				info->color = 0x00FFFFFF;
			point = rota(info, info->tab_point[x][y]);
			my_mlx_pixel_put(&info->img, point.x + WIDTH / 2 * info->zoom, point.y + HEIGHT / 2 * info->zoom, info->color);
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

char	*get_no_color(char	*splitted)
{
	int		i;
	char	*ret;

	if (!splitted)
		return (NULL);
	i = 0;
	while (splitted[i] && splitted[i] != ' ' && splitted[i] != ',' && splitted[i] != '\0' && splitted[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (splitted[i] && splitted[i] != ' ' && splitted[i] != ',' && splitted[i] != '\0' && splitted[i] != '\n')
	{
		ret[i] = splitted[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
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
				free_fun(info);
			info->tab_point[j][i].x = i - info->nbline / 2;
			info->tab_point[j][i].y = j - info->nbcol / 2;
			info->tab_point[j][i].z = ft_atoi(nocolorcode);
			free(nocolorcode);
			i++;
		}
		j++;
		tmp_map = tmp_map->next;
		free(splitmap);
	}
	info->nbline = j;
	info->nbcol = i;
	get_mid(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (-1);
	init_info(&info);
	fill_map(&info.map, argv);
	info.tab_point = malloc(sizeof(t_point *) * map_size(info));
	if (!info.tab_point)
		return (-1);
	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, 1920, 1080, "Fil De Fer");
	info.img.img = mlx_new_image(info.mlx, 1920, 1080);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel, &info.img.line_length, &info.img.endian);
	get_tab_point(&info);
	print_point(&info);
	mlx_hook(info.window, 17, 0, closewin, &info);
	mlx_hook(info.window, 2, 1L << 0, hook, &info);
	mlx_loop(info.mlx);
	return (1);
}
