/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:13 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/06 15:06:12 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*get_no_color(char	*splitted)
{
	int		i;
	char	*ret;

	if (!splitted)
		return ("\0");
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
	if (info.map == NULL)
		return (1);
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
