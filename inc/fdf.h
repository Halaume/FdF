/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:07:03 by ghanquer          #+#    #+#             */
/*   Updated: 2022/03/03 19:03:10 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

# define BUFFER_SIZE 1
# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map_list {
	char				*line;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_info {
	void				*mlx;
	void				*window;
	int					nbcol;
	int					nbline;
	int					yval;
	int					xval;
	int					epaisseur;
	int					projection;
	int					color;
	int					colorbool;
	int					freetab;
	unsigned long long	nb_point;
	double				angle_x;
	double				angle_y;
	double				angle_z;
	double				spacing;
	double				zoom;
	t_point				**tab_point;
	t_point				**save;
	t_point				mid;
	t_data				img;
	t_map_list			*map;
}	t_info;

//				INIT

void		init_info(t_info *info);
void		get_mid(t_info *info);
int			size_of_line(char **line);
int			size_of_col(t_info *info);
void		get_spacing(t_info *info);

//				MLX

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			closewin(t_info *info);
int			hook(int keycode, t_info *info);
void		print_point(t_info *info);

//				MAP

void		fill_map(t_map_list **map, char **argv);
int			map_size(t_info info);
void		retrace_map(t_info *info);

//				GNL && PARSING

char		*get_next_line(int fd);
int			ft_strlen(char *str);
int			check_line(char *str);
int			fill_line(char *line, char *buffer, int j, int i);
char		*ft_join(char *line, char *buffer);
char		*get_line(int fd, char *line);
char		*del_start(char *line);
char		*get_start(char *line);
char		*get_next_line(int fd);
char		*get_no_color(char	*splitted);

//				String Manip

char		**ft_split(char *s, char c);
char		*ft_strdup(char *s);
int			ft_atoi(char *str);

//				Chain List utils

void		map_add_back(t_map_list **alst, t_map_list *new);
t_map_list	*lst_map_new(char *line);
void		alloctab_point(t_info *info);

//				ISOMETRIE

t_point		rota(t_info *info, t_point point);
void		bresenham(t_info *info, t_point point1, t_point point2);
void		bricenham(t_info *info, t_point point1, t_point point2);

//				ERROR / free

void		free_fun(t_info *info);
void		free_list(t_info *info);
void		free_map(char **splitmap);

//				HOOK FUN

void		reset(t_info *info);
void		gauche(t_info *info);
void		droite(t_info *info);
void		haut(t_info *info);
void		bas(t_info *info);
void		zoom_in(t_info *info);
void		zoom_out(t_info *info);
void		high(t_info *info);
void		low(t_info *info);
void		projection(t_info *info);
void		rota_up(t_info *info);
void		rota_left(t_info *info);
void		rota_down(t_info *info);
void		rota_right(t_info *info);
void		color(t_info *info);

#endif
