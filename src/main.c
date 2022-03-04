/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/04 18:09:49 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	dist(t_point mid, t_point point)
{
	int		dist;
	t_point	final_point;

	dist = sqrt((pow((mid.x - point.x), 2)) + (pow((mid.y - point.y), 2)) + \
			(pow((mid.z - point.z), 2)));
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

char	*get_no_color(char	*splitted)
{
	int		i;
	char	*ret;

	if (!splitted)
		return (NULL);
	i = 0;
	while (splitted[i] && splitted[i] != ' ' && splitted[i] != ',' && \
			splitted[i] != '\0' && splitted[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (splitted[i] && splitted[i] != ' ' && splitted[i] != ',' && \
			splitted[i] != '\0' && splitted[i] != '\n')
	{
		ret[i] = splitted[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (1);
	init_info(&info);
	fill_map(&info.map, argv);
	info.mlx = mlx_init();
	info.window = mlx_new_window(info.mlx, 1920, 1080, "Fil De Fer");
	info.img.img = mlx_new_image(info.mlx, 1920, 1080);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel, \
			&info.img.line_length, &info.img.endian);
	get_tab_point(&info);
	print_point(&info);
	mlx_hook(info.window, 17, 0, closewin, &info);
	mlx_hook(info.window, 2, 1L << 0, hook, &info);
	mlx_loop(info.mlx);
	return (1);
}
