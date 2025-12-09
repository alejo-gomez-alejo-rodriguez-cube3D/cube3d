
NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

# --- DIRECTORIOS ---
SRC_DIR     = src
OBJ_DIR     = obj

# --- CONFIGURACIÓN LIBFT ---
LIBFT_DIR   = libs/libft
LIBFT       = $(LIBFT_DIR)/libft.a

# --- CONFIGURACIÓN MINILIBX (Linux) ---
MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx_Linux.a
# CAMBIO CLAVE: Usamos -lmlx_Linux (Con L mayúscula)
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

# --- SOURCES ---
PARSER_SRCS = src/parser/parse_file.c \
              src/parser/parse_textures.c \
              src/parser/parse_colors.c \
              src/parser/parse_map.c \
              src/parser/validate_map.c \
              src/parser/parser_utils.c

RENDER_SRCS = src/render/render.c \
              src/render/render_utils.c

RAYCAST_SRCS = src/raycasting/raycasting.c \
               src/raycasting/raycasting_utils.c

UTILS_SRCS  = src/utils/error.c \
              src/utils/free.c \
              src/utils/utils.c

MAIN_SRC    = src/main.c

# Combinamos todo
SRCS        = $(MAIN_SRC) $(PARSER_SRCS) $(RENDER_SRCS) $(RAYCAST_SRCS) $(UTILS_SRCS)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- REGLAS ---

all: $(NAME)

# 1. Regla para compilar Libft
$(LIBFT):
	@echo "📚 Compilando Libft..."
	@make -C $(LIBFT_DIR)

# 2. Regla para compilar MiniLibX
$(MLX):
	@echo "🎮 Compilando MiniLibX..."
	-@make -C $(MLX_DIR)

# 3. Regla principal
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "🔗 Enlazando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) creado exitosamente!"

# Compilación de objetos
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