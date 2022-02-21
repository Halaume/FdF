/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:03 by ghanquer          #+#    #+#             */
/*   Updated: 2022/02/21 17:33:38 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_info {
	void	*mlx;
	void	*window;
	t_data	img;
}	t_info;

//				GNL

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		check_line(char *str);
int		fill_line(char *line, char *buffer, int j, int i);
char	*ft_join(char *line, char *buffer);
char	*get_line(int fd, char *line);
char	*del_start(char *line);
char	*get_start(char *line);
char	*get_next_line(int fd);

char	**ft_split(char *s, char c);

#endif
