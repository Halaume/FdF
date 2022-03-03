/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:59:19 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 17:31:06 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	close(fd);
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

t_point	rota(t_info *info, t_point point)
{
	t_point	res;

	res.x = (info->spacing * (cos(info->angle_z) * point.x - \
				sin(info->angle_z) * point.y));
	res.y = (info->spacing * (sin(info->angle_z) * point.x + \
				cos(info->angle_z) * point.y));
	res.y = (res.y * cos(info->angle_x)) - ((point.z * \
				info->spacing / info->epaisseur) * sin(info->angle_x));
	res.z = point.z;
	res.y += info->yval;
	res.x += info->xval;
	return (res);
}
