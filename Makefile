#==================================================
# CONSTANT
#==================================================

CC = gcc
FLAG = -Wall -Werror -Wextra -O3
RM = rm -f

#==================================================
# DECLARATION
#==================================================

NAME = cub3D
INCLUDE = ./_include/mlx/libmlx.a ./_include/lib/libft.a
MLX_FLAG = -L./_include/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

LIB_DIR = ./_include/lib
MLX_DIR = ./_include/mlx

#==================================================
# FILES
#==================================================

SRC = $(wildcard ./draw/*.c) \
	$(wildcard ./extract/*.c) \
	$(wildcard ./game/*.c) \
	$(wildcard ./init/*.c) \
	$(wildcard ./render/*.c) \
	$(wildcard ./validate/*.c) \
	$(wildcard ./utils/*.c) \
	
SRC_M = ./bonus/valid_map_util.c
SRC_B = ./bonus/valid_map_util_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

#===================================================
# BUILD
#===================================================

all : lib $(NAME)
bonus : lib mkbonus

$(NAME) : $(OBJ) $(OBJ_M)
	$(CC) $(FLAG) -o $@ $^ $(INCLUDE) $(MLX_FLAG) 

mkbonus: $(OBJ) $(OBJ_B)
	$(CC) $(FLAG) -o $(NAME) $^ $(INCLUDE) $(MLX_FLAG) 

lib:
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_M) $(OBJ_B)
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	make -C $(LIB_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all bonus lib clean fclean re
