/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/23 11:52:35 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	closewin(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->window);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	exit (0);
	return (1);
}

void	fill_map(t_map_list **map, char **argv)
{
	int			fd;
	char		*tmp;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return ;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		map_add_back(map, lst_map_new(ft_strdup(tmp)));
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	map_size(t_info info)
{
	t_map_list	*tmp;
	int			i;

	i = 0;
	tmp = info.map;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	print_tab_point(t_info info)
{
	int	i;

	i = 0;
	while (info.tab_point[i])
	{
		printf("x : %d, y : %d, z : %d\n", info.tab_point[i]->x, info.tab_point[i]->y, info.tab_point[i]->z);
		i++;
	}
}

void	print_point(t_info info)
{
	int			i;
	int			j;
	char		**splitmap;
	t_map_list	*tmp_map;

	j = 0;
	tmp_map = info.map;
	alloctab_point(&info);
	while (tmp_map)
	{
		i = 0;
		printf("line : %s", tmp_map->line);
		splitmap = ft_split(tmp_map->line, ' ');
		while (splitmap[i])
		{
			info.tab_point[j][i].x = i;
			printf("-----START-----\nx : %d\n", info.tab_point[j]->x);
			info.tab_point[j][i].y = j;
			printf("y : %d\n", info.tab_point[j]->y);
			info.tab_point[j][i].z = ft_atoi(splitmap[i]);
			printf("z : %d\n", info.tab_point[j]->z);
			i++;
		}
		j++;
		tmp_map = tmp_map->next;
		free(splitmap);
	}
	print_tab_point(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (-1);

	info_init(&info);
	fill_map(&info.map, argv);
	info.tab_point = malloc(sizeof(t_point *) * map_size(info));
	if (!info.tab_point)
		return (-1);
	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, 1920, 1080, "Fil De Fer");
	info.img.img = mlx_new_image(info.mlx, 1920, 1080);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel, &info.img.line_length, &info.img.endian);
	my_mlx_pixel_put(&info.img, 5, 5, info.color);
	print_point(info);
	mlx_put_image_to_window(info.mlx, info.window, info.img.img, 0, 0);
	mlx_hook(info.window, 17, 0, closewin, &info);
	mlx_loop(info.mlx);
	return (1);
}
