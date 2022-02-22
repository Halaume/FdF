# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 14:08:14 by ghanquer          #+#    #+#              #
#    Updated: 2022/02/22 15:52:35 by ghanquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_DIR =		inc
OBJ_DIR = 		obj
SRC_DIR	= 		src

SRC =			$(SRC_FT:%=$(SRC_DIR)/%.c)

OBJ =			$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS =		$(OBJ_DIR)

CC = clang $(CFLAGS)

RM = rm -fr

CFLAGS = -Wall -Wextra -Werror

MLX = minilibx-linux/libmlx_Linux.a

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

#HOW TO LIST .c 
#	ls -l | awk '{print $9}' | grep -E ".c$"| sed "s/\.c/ \\\/g" | sed '$s/\\$//g'

SRC_FT = 	main \
			free_fun \
			lst_map_fun \
			get_next_line \
			ft_split \
			fdf_utils \
			get_next_line_utils

all: $(NAME)

$(OBJ_DIRS): inc/fdf.h
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(SRC) $(MLX)
	$(MAKE) -j $(OBJ)
	$(CC) $(OBJ) $(MLX) -lXext -lX11 -lm -Iminilibx -o $@

$(MLX):
	$(MAKE) -C ./minilibx-linux

clean:
	$(RM) $(OBJ_DIR)

debugclean:
	$(RM) debug

fclean: clean debugclean
	$(RM) $(NAME)

re: fclean all

debug:
	$(CC) -g3 -fsanitize=address $(OBJ) $(MLX) -lXext -lX11 -lm -Iminilibx -o $@

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "             \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                                {"
	@echo "                             {   }"
	@echo "                              }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                           \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                          \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                          \0033[1;34m| -.._____..- |"
	@echo "                          |             ;--."
	@echo "                          |            (__  \ "
	@echo "                          |             | )  )"
	@echo "                          |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                          |             /  / "
	@echo "                          |            (  / "
	@echo "                          \             | "
	@echo "                            -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

.SECONDARY: $(OBJ) $(OBJ_DIR)
.PHONY: all clean fclean re coffee debug debugclean
