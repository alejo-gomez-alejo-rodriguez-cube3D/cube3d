
NAME        = cub3D

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
              src/parser/parser_utils.c

RENDER_SRCS = src/render/render.c \
              src/render/render_utils.c \
			  src/render/buttons.c \

RAYCAST_SRCS = src/raycasting/raycasting.c \
               src/raycasting/raycasting_utils.c

UTILS_SRCS  = src/utils/error.c \
              src/utils/free.c \
              src/utils/utils.c

MAIN_SRC    = src/main.c

SRCS        = $(MAIN_SRC) $(PARSER_SRCS) $(RENDER_SRCS) $(RAYCAST_SRCS) $(UTILS_SRCS)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "🎮 Compilando MiniLibX..."
	-@make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "🔗 Enlazando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) creado exitosamente!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "📦 Compilando $<..."
	@$(CC) $(CFLAGS) -I. -I$(MLX_DIR) -c $< -o $@

clean:
	@echo "🧹 Limpiando objetos..."
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@echo "🧹 Limpiando ejecutable..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re