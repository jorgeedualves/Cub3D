# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:38:22 by joeduard          #+#    #+#              #
#    Updated: 2022/10/21 18:49:17 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME			=	cub3d

# CC				=	clang

# LIB				=	./libraries/libft/libft.a
# MLX				=	./libraries/mlx_linux/libmlx.a

# #XPM_DIR = textures
# IMG_DIR = assets/img

# FLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address
# LIBFLAGS			=	-lbsd -lX11 -lXext
# INC				=	-I ./includes -I ./libft -I ./mlx_linux -I./src/validations

# SRC_DIR			=	./src
# OBJ_DIR			=	./obj

# FILES			=	cub3d.c
# FILES			+=	event_handler.c exit_game.c game_utils.c get_next_line.c hook_player.c init_data.c \
# 					init_image.c init_window.c map_check.c map_render.c map_utils.c  move_player.c player_update.c \
# 					read_map.c valid_map.c

# HEADERS			=	cub3d.h \
# 					defines.h \
# 					validation.h \
# 					erros.h \
# 					structs.h \

# SRC				=	$(addprefix $(SRC_DIR)/, $(FILES))

# OBJ				=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# all:			$(NAME)

# $(NAME):	$(LIB) $(MLX) $(OBJ) $(HEADERS) 
# 	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) $(LIBFLAGS) $(INC) -o $(NAME)
# 	@echo -e '\e[42;37;01m Game created! \e[m'

# $(OBJ_DIR)/%.o:  $(HEADERS) $(SRC_DIR)/%.c
# 	@mkdir -p obj
# 	$(CC) $(FLAGS) $(INC) -c $< -o $@
# 	@echo -e '\e[42;37;01m OBJ_DIR and objs! [ OK ] \e[m'
	
# $(LIB):
# 	make -C libraries/libft

# $(MLX):
# 	@echo -e '\e[44;37;01m Compiling MLX [ .. ] \e[m'
# 	@make -C libraries/mlx_linux
# 	@echo -e '\e[42;37;01m Mlx is ready! [ OK ] \e[m'

# run:
# 	./cub3d "assets/maps/map.cub"

# clean:
# 	@make -C ./libraries/libft clean
# 	@make -C ./libraries/mlx_linux clean
# 	@rm -fr obj
# 	@echo -e '\e[41;37;01m Objects files deleted. \e[m'

# fclean:	clean
# 	@rm -f $(NAME) $(LIB) $(MLX)
# 	@echo -e '\e[41;37;01m Executable deleted. \e[m'

# bonus:	$(NAME)

# norm:
# 	norminette src includes libft

# re:		fclean all

# .PHONY:	all, clean, fclean, bonus, re


#TESTE 2 -------------------------------------------------------
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
validation		=	map_check.c read_map.c valid_map.c validation.c

FILES			=	$(addprefix core/, $(core)) \
					$(addprefix draw/, $(draw)) \
					$(addprefix int/, $(int)) \
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


#----------------------------------------------------------------

# TESTE 3

# NAME			=	cub3d

# CC				= 	clang

# LIB				=	./libraries/libft/libft.a
# MLX				=	./libraries/mlx_linux/libmlx.a

# FLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address

# LIBFLAGS		=	-lbsd -lX11 -lXext

# INC				=	-I ./includes -I ./$(LIB) -I ./$(MLX)

# SRC_DIR			=	./src

# RM				=	rm -rf

# core			=	cub3d.c exit_game.c move_player.c player_update.c
# draw			=	map_render.c map_utils.c
# init			=	init_data.c init_image.c init_window.c
# keys			=	event_handler.c game_utils.c kook_player.c
# validation		=	map_check.c read_map.c valid_map.c validation.c

# FILES			=	$(addprefix core/, $(core)) \
# 					$(addprefix draw/, $(draw)) \
# 					$(addprefix int/, $(int)) \
# 					$(addprefix keys/, $(keys)) \
# 					$(addprefix validations/, $(validations))

# SRC				=	$(addprefix $(SRC_DIR)/, $(FILES))