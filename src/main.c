/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:49 by ghanquer         ###   ########.fr       */
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

void	fill_map(t_map_list *map, int fd)
{
	t_map_list	*lst_tmp;
	char		*tmp;

	tmp = "init";
	lst_tmp = map;
	while (tmp != NULL)
	{
		map_add_back(&map, lst_map_new(get_next_line(fd)));
		lst_tmp = lst_tmp->next;
		tmp = lst_tmp->line;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		fd_open;

	(void)argc;

	fd_open = open(argv[2], O_RDONLY);
	if (!fd_open)
		return (-1);
	fill_map(info.map, fd_open);
	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, 1920, 1080, "Fil De Fer");
	info.img.img = mlx_new_image(info.mlx, 1920, 1080);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel, &info.img.line_length, &info.img.endian);
	my_mlx_pixel_put(&info.img, 5, 5, info.color);
	mlx_put_image_to_window(info.mlx, info.window, info.img.img, 0, 0);
	mlx_hook(info.window, 17, 0, closewin, &info);
	mlx_loop(info.mlx);
	return (1);
}
