C = cc

LIBFT_DIR = libft
MLX_DIR = minilibx

LIBFT_NAME = libft.a
LIBFT_A = $(LIBFT_DIR)/$(LIBFT_NAME)

MLX_NAME = libmlx.a
MLX_A = $(MLX_DIR)/$(MLX_NAME)

OBJ_DIR = build/objects
OUTPUT_DIR = build/outputs

LIBFT_OUTPUT = $(OUTPUT_DIR)/$(LIBFT_NAME)
MLX_OUTPUT = $(OUTPUT_DIR)/$(MLX_NAME)

CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -L$(MLX_DIR) -Imlx_linux -lX11 -lXext -lmlx -lm -lz

NAME = $(OUTPUT_DIR)/fdf

SRC = main.c \
		service/fdf.c \
		service/get_next_line.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OUTPUT) $(MLX_OUTPUT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OUTPUT) $(MLX_OUTPUT) $(MLXFLAGS) -o $(NAME)

$(LIBFT_OUTPUT): $(LIBFT_A)
	mkdir -p $(OUTPUT_DIR)
	cp $< $@

$(MLX_OUTPUT): $(MLX_A)
	mkdir -p $(OUTPUT_DIR)
	cp $< $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(MLX_A):
	make -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c headers/fdf.h headers/get_next_line.h Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(OUTPUT_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
