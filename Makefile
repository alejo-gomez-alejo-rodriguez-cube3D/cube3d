NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

PARSER_SRCS = src/parser/parse_file.c \
              src/parser/parse_textures.c \
              src/parser/parse_colors.c \
              src/parser/parse_map.c \
              src/parser/validate_map.c \
              src/parser/parser_utils.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \

RENDER_SRCS = src/render/render.c \
              src/render/render_utils.c

RAYCAST_SRCS = src/raycasting/raycasting.c \
               src/raycasting/raycasting_utils.c

UTILS_SRCS = src/utils/error.c \
             src/utils/free.c \
             src/utils/utils.c

MAIN_SRC = src/main.c

SRCS = $(MAIN_SRC) $(PARSER_SRCS) $(RENDER_SRCS) $(RAYCAST_SRCS) $(UTILS_SRCS)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🔗 Enlazando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ $(NAME) creado exitosamente!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "📦 Compilando $<..."
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@echo "🧹 Limpiando objetos..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🧹 Limpiando ejecutable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
