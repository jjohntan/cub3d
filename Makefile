#==================================================
# CONSTANT
#==================================================

CC = gcc
FLAG = -Wall -Werror -Wextra -O3
RM = rm -f

#==================================================
# DECLARATION
#==================================================

NAME = cub3d
INCLUDE = ./_include/mlx/libmlx.a ./_include/lib/libft.a
MLX_FLAG = -L./_include/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

LIB_DIR = ./_include/lib
MLX_DIR = ./_include/mlx

#==================================================
# FILES
#==================================================

SRC = $(wildcard ./dummy/*.c) \
	$(wildcard ./game/*.c) \
	$(wildcard ./init/*.c) \
	$(wildcard ./render/*.c) \
	$(wildcard ./utils/*.c)
OBJ = $(SRC:.c=.o)

#===================================================
# BUILD
#===================================================

all : lib $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(INCLUDE) $(MLX_FLAG) 

lib:
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all bonus lib clean fclean re
