NAME = cub3d
CC = cc
FLAG = -Wall -Werror -Wextra
INC = -I $(MLX_DIR) -I ./inc
MLX_DIR = ./minilibx-linux
MLX_EXEC = -L{MLX_DIR} -lmlx -lm -lX11 -lXext
LIBFT = ./libft
FILES = $(addprefix ./src/, main init render utils hook)
SRCS = $(FILES:=.c)

all : ${NAME}

${NAME} :
	@make -C ${LIBFT}
	${CC} -g ${SRCS} ${MLX_EXEC} ${INC} -o ${NAME}

clean :
	@make clean -C ${LIBFT}
	@rm -f bonus

fclean :
	@make fclean -C ${LIBFT}
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
