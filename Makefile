# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:38:22 by joeduard          #+#    #+#              #
#    Updated: 2022/08/24 16:28:18 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

CC				=	clang

LIB				=	./libraries/libft/libft.a
MLX				=	./libraries/mlx_linux/libmlx.a

XPM_DIR = textures
IMG_DIR = assets/img

FLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address
LIBFLAGS			=	-lbsd -lX11 -lXext
INC				=	-I ./includes -I ./libft -I ./mlx_linux

SRC_DIR			=	./src
OBJ_DIR			=	./obj

FILES			=	cub3d.c
FILES			+=	exit_game.c get_next_line.c init_game.c init_image.c init_window.c \
					map_check.c map_utils.c read_map.c valid_map.c 

SRC				=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ				=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all:			$(NAME)

$(NAME):	$(LIB) $(MLX) $(OBJ) 
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) $(LIBFLAGS) $(INC) -o $(NAME)
	@echo "Game created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@
	
$(LIB):
	make -C libraries/libft

$(MLX):
	@echo "Compiling MLX [ .. ]"
	@make -C libraries/mlx_linux
	@echo "Mlx is ready! [ OK ]"

run:
	./cub3d "assets/maps/map.cub"

clean:
	@make -C ./libraries/libft clean
	@make -C ./libraries/mlx_linux clean
	@rm -fr obj
	@echo "Objects files deleted."

fclean:	clean
	@rm -f $(NAME) $(LIB) $(MLX)
	@make -C ./libft fclean
	@echo "Executable deleted."

bonus:	$(NAME)

norm:
	norminette src includes libft

re:		fclean all

.PHONY:	all, clean, fclean, bonus, re