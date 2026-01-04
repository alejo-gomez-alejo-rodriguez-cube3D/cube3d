NAME        = cub3D
NAME_BONUS  = cub3D_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

SRC_DIR     = src
OBJ_DIR     = obj

LIBFT_DIR   = libs/libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

PARSER_SRCS = src/parser/parse_file.c \
              src/parser/parse_textures.c \
              src/parser/parse_colors.c \
              src/parser/parse_map.c \
              src/parser/validate_map.c \
              src/parser/parser_utils.c \
              src/parser/map_utils.c \
              src/parser/check_walls.c

RENDER_SRCS = src/render/render.c \
              src/render/render_utils.c \
              src/render/buttons.c \
              src/render/rot_buttons.c \
              src/render/hooks.c \
              src/render/load_textures.c

RAYCAST_SRCS = src/raycasting/raycasting.c \
               src/raycasting/raycasting_utils.c \
               src/raycasting/compute_ray.c \
               src/raycasting/dda.c \
               src/raycasting/drawing.c

UTILS_SRCS  = src/utils/error.c \
              src/utils/free.c \
              src/utils/utils.c

MAIN_SRC    = src/main.c

SRCS        = $(MAIN_SRC) $(PARSER_SRCS) $(RENDER_SRCS) $(RAYCAST_SRCS) $(UTILS_SRCS)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_MAIN  = src/main_bonus.c
BONUS_EXTRA = bonus/minimap.c 

BONUS_SRCS  = $(BONUS_MAIN) $(BONUS_EXTRA) \
              $(PARSER_SRCS) $(RENDER_SRCS) $(RAYCAST_SRCS) $(UTILS_SRCS)

BONUS_OBJS  = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@make -sC $(LIBFT_DIR)

$(MLX):
	@echo "🎮 Compilando MiniLibX..."
	@make -sC $(MLX_DIR) > /dev/null 2>&1 || true

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) creado exitosamente!"

$(NAME_BONUS): $(LIBFT) $(MLX) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "✅ $(NAME_BONUS) creado exitosamente!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I. -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean > /dev/null 2>&1 || true
	@make -sC $(MLX_DIR) clean > /dev/null 2>&1 || true
	@echo "🧹 Objetos eliminados."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -sC $(LIBFT_DIR) fclean > /dev/null 2>&1 || true
	@echo "🧹 Ejecutables eliminados."

re: fclean all

.PHONY: all clean fclean re bonus