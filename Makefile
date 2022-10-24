# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:38:22 by joeduard          #+#    #+#              #
#    Updated: 2022/10/24 16:12:54 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address


LIBFT_DIR		=	./libraries/libft
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFLAGS		=	-L $(LIBFT_DIR) -lft

MLX_DIR			=	./libraries/mlx_linux
MLX				=	$(MLX_DIR)/libmlx.a
MLXFLAGS		=	-L $(MLX_DIR) -lmlx_Linux -lbsd -lX11 -lXext

INC				=	-I ./includes -I ./$(LIBFT_DIR) -I ./$(MLX_DIR)

SRC_DIR			=	./src/

RM				=	rm -rf

core			=	cub3d.c exit_game.c move_player.c player_update.c
draw			=	map_render.c map_utils.c
init			=	init_data.c init_image.c init_window.c
keys			=	event_handler.c game_utils.c hook_player.c
validations		=	map_check.c read_map.c valid_map.c validation.c

FILES			=	$(addprefix core/, $(core)) \
					$(addprefix draw/, $(draw)) \
					$(addprefix init/, $(init)) \
					$(addprefix keys/, $(keys)) \
					$(addprefix validations/, $(validations)) \

SRC				=	$(FILES)

OBJS_DIR		=	./obj/
OBJS			=	$(addprefix $(OBJS_DIR),$(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
				@echo -e '\e[44;37;01m Compiling LIBFT [ .. ] \e[m'
				make -C $(LIBFT_DIR)
				@echo -e '\e[42;37;01m LIBFT is ready! [ OK ] \e[m'
				@echo -e '\e[44;37;01m Compiling MLX [ .. ] \e[m'
				make -C $(MLX_DIR)
				@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFLAGS) $(LIBFT) $(MLXFLAGS) -o $@
				@echo -e '\e[42;37;01m MLX is ready! [ OK ] \e[m'

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p obj/core
				@mkdir -p obj/draw
				@mkdir -p obj/init
				@mkdir -p obj/keys
				@mkdir -p obj/validations
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

run:
	./cub3d "assets/maps/mandatory.cub"

clean:
				make -C $(LIBFT_DIR) fclean
				make -C $(MLX_DIR) clean
				@echo -e '\e[41;37;01m Executable deleted. \e[m'

fclean:			clean
				$(RM) obj
				$(RM) $(NAME)

re:				fclean all

add:			fclean
				git add .
				git status

install:
				@sudo apt-get install libxext-dev libbsd-dev

.PHONY:			all clean fclean re
