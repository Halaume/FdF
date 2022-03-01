/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:59:19 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/01 12:35:23 by ghanquer         ###   ########.fr       */
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

t_point	*prod_mat(t_point *p1, t_point *p2)
{
	t_point	*res;

	if (!p1 || !p2)
		return (NULL);
	res = p1;
	return (res);
}
