# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 15:00:04 by jajuntti          #+#    #+#              #
#    Updated: 2024/03/21 15:36:05 by jajuntti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -g -fsanitize=address #-Wall -Wextra -Werror 

SRC_DIR = src/
SRC =	so_long.c \
		init.c \
		map_checks.c \
		clean.c \
		quit.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = obj/
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

LIB_DIR = libft/
LIBFT = libft.a
LIB_PATH = $(LIB_DIR)$(LIBFT)

MLX42_DIR = mlx42/
MLX42 = libmlx42.a
MLX42_PATH = $(MLX42_DIR)build/$(MLX42)
MLX42_LIB = $(MLX42_PATH) -L ~/.brew/opt/glfw/lib -lglfw -ldl -pthread -lm

INC = -I includes/ -I $(LIB_DIR) -I $(MLX42_DIR)include/

all: $(NAME)
	
$(NAME): $(LIB_PATH) $(MLX42_PATH) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) $(MLX42_LIB) -o $(NAME) $(INC)

$(LIB_PATH): $(LIBFT)
$(LIBFT):
	make -C $(LIB_DIR)

$(MLX42_PATH): $(MLX42)
$(MLX42):
	cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	make -C $(MLX42_DIR)/build -j4

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	$(CC) $(CFLAGS) -I $(MLX42_DIR)include -c $< -o $@ $(INC)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_PATH)
	rm -f $(MLX42_PATH)

re: fclean all

.PHONY: all bonus clean fclean re