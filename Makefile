# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/30 18:07:29 by ocojeda-          #+#    #+#              #
#    Updated: 2019/05/03 12:54:41 by ocojeda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
GCC_FLGS = -Wall -Wextra -Werror
MINILIBX = minilibx_macos/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit -lxml2
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./includes/ $(LIB_PATH)libft/include/ $(LIB_PATH)libmat4/include/
LIB_NAME = libft libmat4

SRC_NAME = parse.c init_data.c find_the_wall.c init_mlx.c keycode.c main.c \
			bitmap_parser.c colors.c init_calc_find_the_wall.c\
			ret_colors.c parse_wall_final_adder.c map_range.c \
			draw.c

OBJ_NAME = $(SRC_NAME:.c=.o)
	
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): mlx $(OBJ)
	make -C $(LIB_PATH)libft -j
	make -C $(LIB_PATH)libmat4 -j
	$(CC) $(GCC_FLGS) $(MINILIBX) $(MLXFLAGS) $(LIB) -lft -lmat4 $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

mlx:
	@printf "$(YELLOW)[MINILIBX] Compiling obj...                                                     \r$(NO_COLOR)"
	@make -s -C minilibx_macos/ 2> /dev/null > /dev/null

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)
	@make clean -C minilibx_macos

fclean: clean
	make -C $(LIB_PATH)libft fclean
	make -C $(LIB_PATH)libmat4 fclean
	@/bin/rm -rf $(NAMEBIN)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---Wolf3D removed completely---$(NC)"

re: fclean all

.PHONY: all clean fclean re
