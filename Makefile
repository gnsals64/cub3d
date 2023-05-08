NAME = cub3d
CC = cc
FLAG = -Wall -Werror -Wextra
INC = -I $(MLX_DIR) -I ./inc
MLX_DIR = ./minilibx-linux
MLX_EXEC = $(MLX_DIR)/libmlx.a -lXext -lX11 -lm -lbsd
LIBFT = ./libft
FILES = $(addprefix ./, test)
SRCS = $(FILES:=.c)

all : ${NAME}

${NAME} :
	@make -C ${LIBFT}
	@${CC}  ${SRCS} ${MLX_EXEC} ${INC} -o ${NAME}

clean :
	@make clean -C ${LIBFT}
	@rm -f bonus

fclean :
	@make fclean -C ${LIBFT}
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
