# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 09:24:56 by ocojeda-          #+#    #+#              #
#    Updated: 2019/01/23 15:07:41 by ocojeda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = libmat4.a
CC = gcc
CFGLAGS = -Werror -Wextra -Wall -g

SRC_NAME  = mat4_set.c mat4_copy.c mat4_add.c mat4_sub.c mat4_mul.c \
			mat4_transpose.c mat4_scale.c mat4_rotate.c \
			vec3_add.c vec3_cross.c vec3_dot.c vec3_fmul.c \
			vec3_magnitude.c vec3_mul.c vec3_normalize.c vec3_rotate.c \
			vec3_scale.c vec3_set.c vec3_sub.c vec3_copy.c vec.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
