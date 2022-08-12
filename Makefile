NAME = cub3d

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX_DIR = libraries/mlx_linux
# MLX = $(MLX_DIR)/libmlx.a

RM = rm -rf

#IMG_DIR = assets/IMG_DIR

SRC_DIR = src

OBJ_DIR = obj

HEADERS = includes/cub3d.h

INCLUDE_DIR = includes

SRC_FILES = cub3d.c map_check.c read_map.c valid_map.c  get_next_line.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

cc = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run: ./$(NAME) "assets/maps/map.ber"

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
		make -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re