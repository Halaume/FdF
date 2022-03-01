/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/01 13:04:08 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	dist(t_point mid, t_point point)
{
	int		dist;
	t_point	final_point;

	dist = sqrt((pow((mid.x - point.x), 2)) + (pow((mid.y - point.y), 2)) + (pow((mid.z - point.z), 2)));
	final_point.x = point.x + dist;
	final_point.y = point.y + dist;
	final_point.z = point.z;
	return (final_point);
}

void	print_point(t_info *info)
{
	int	x;
	int	y;
	int	line;

	x = 0;
	while (x < info->nbcol)
	{
		y = 0;
		while (y < info->nbline)
		{
			line = 0;
			if (info->tab_point[x][y].z > 0)
				info->color = 0x00FF0F0F;
			else if (info->tab_point[x][y].z < 0)
				info->color = 0x00FF0FF0;
			else
				info->color = 0x00FFFFFF;
			if (x != info->nbcol - 1)
			{
				while (line <= info->spacing)
				{
					my_mlx_pixel_put(&info->img, info->tab_point[x][y].x * info->spacing + WIDTH / 2 * info->zoom, info->tab_point[x][y].y * info->spacing + HEIGHT / 2 + line * info->zoom, info->color);
					line++;
				}
			}
			if (y != info->nbline - 1)
			{
				line = 0;
				while (line <= info->spacing)
				{
					my_mlx_pixel_put(&info->img, info->tab_point[x][y].x * info->spacing + WIDTH / 2 + line * info->zoom, info->tab_point[x][y].y * info->spacing + HEIGHT / 2 * info->zoom, info->color);
					line++;
				}
			}
			my_mlx_pixel_put(&info->img, info->tab_point[x][y].x * info->spacing + WIDTH / 2 * info->zoom, info->tab_point[x][y].y * info->spacing + HEIGHT / 2 * info->zoom, info->color);
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
			printf(" %.2d ", info->tab_point[j][i].z);
//			printf("x = %d y = %d\n", info->tab_point[j][i].x, info->tab_point[j][i].y);
			free(nocolorcode);
			i++;
		}
		printf("\n");
		j++;
		tmp_map = tmp_map->next;
		free(splitmap);
	}
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
	mlx_loop(info.mlx);
	return (1);
}
