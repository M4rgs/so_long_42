NAME = so_long

NAME_BONUS = so_long_bonus

GCC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = Mendatory/src/so_long.c Mendatory/src/checker.c Mendatory/src/map.c Mendatory/src/render.c Mendatory/src/utils.c Mendatory/src/init.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC_BONUS = bonus/src/so_long_bonus.c bonus/src/checker_bonus.c bonus/src/map_bonus.c bonus/src/render_bonus.c bonus/src/utils_bonus.c bonus/src/init_bonus.c bonus/src/enemy_bonus.c bonus/src/helpme_bonus.c bonus/src/animation_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MLX = mlx/libmlx.a

MLX_FLAGS = -lXext -lX11

AR = ar -rc

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${GCC} ${CFLAGS} ${OBJ} ${MLX} ${MLX_FLAGS} -o ${NAME}

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS}
	${GCC} ${CFLAGS} ${OBJ_BONUS} ${MLX} ${MLX_FLAGS} -o ${NAME_BONUS}

Mendatory/src/%.o : Mendatory/src/%.c Mendatory/so_long.h
	${CC} ${CFLAGS} -c $< -o $@

bonus/src/%.o : bonus/src/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}
re : fclean all

.PHONY : clean