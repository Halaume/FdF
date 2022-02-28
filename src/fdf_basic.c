/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:16:54 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/28 19:10:40 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_info(t_info *info)
{
	info->mlx = NULL;
	info->window = NULL;
	info->tab_point = NULL;
	info->zoom = 1;
	info->map = NULL;
	info->color = 0x00FFFFFF;
	info->nb_point = 0;
}
