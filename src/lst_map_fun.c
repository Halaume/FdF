/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:29:36 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:14 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_map_list	*lst_map_new(char *line)
{
	t_map_list	*tmp;

	tmp = malloc(sizeof(t_map_list));
	if (!tmp)
		return (NULL);
	tmp->line = line;
	tmp->next = NULL;
	return (tmp);
}

void	map_add_back(t_map_list **alst, t_map_list *new)
{
	t_map_list	*tmp;

	if (alst && new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	info_init(t_info *info)
{
	info->color = 0x00FF0000;
	info->mlx = NULL;
	info->window = NULL;
	info->map = NULL;
}
