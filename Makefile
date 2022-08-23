NAME			=	cub3d

CC				=	clang

LIB				=	./libraries/libft/libft.a
MLX				=	./libraries/mlx_linux/libmlx_Linux.a

FLAGS			=	-Wall -Werror -Wextra -g -fsanitize=address
LINKS			=	-lbsd -lX11 -lXext
INC				=	-I ./inc -I ./libft -I ./mlx_linux

SRC_DIR			=	./src
OBJ_DIR			=	./obj

FILES			=	cub3d.c
FILES			+=	get_next_line.c map_check.c read_map.c valid_map.c exit_game.c 

SRC				=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ				=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all:			$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME):	$(LIB) $(OBJ) $(MLX)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) $(LINKS) $(INC) -o $(NAME)
	@echo "Game created!"

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
#	@make -C ./libft fclean
	@echo "Executable deleted."

bonus:	$(NAME)

norm:
	norminette src inc libft

re:		fclean all

.PHONY:	all, clean, fclean, bonus, re