NAME = so_long

NAME_BONUS = so_long_bonus

LIB = so_long.a

LIB_BONUS = so_long_bonus.a

GCC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = Mendatory/so_long.c Mendatory/src/checker.c Mendatory/src/map.c Mendatory/src/render.c Mendatory/src/utils.c Mendatory/src/init.c Mendatory/src/linegrab.c

SRC_BONUS = bonus/so_long_bonus.c bonus/src/checker_bonus.c bonus/src/map_bonus.c bonus/src/render_bonus.c bonus/src/utils_bonus.c bonus/src/init_bonus.c bonus/src/enemy_bonus.c bonus/src/helpme_bonus.c bonus/src/animation.c bonus/src/linegrab.c

MLX = mlx/libmlx.a

MLX_FLAGS = -lXext -lX11

AR = ar -rc

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ} 
	${AR} ${LIB} ${OBJ}
	make -C mlx/
	${GCC} ${CFLAGS} ${LIB} ${MLX} ${MLX_FLAGS} -o ${NAME}

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS} 
	${AR} ${LIB_BONUS} ${OBJ_BONUS}
	make -C mlx/
	${GCC} ${CFLAGS} ${LIB_BONUS} ${MLX} ${MLX_FLAGS} -o ${NAME_BONUS}

%.o : %.c Mendatory/so_long.h bonus/so_long_bonus.h
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	make clean -C mlx/
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}
	${RM} ${LIB}
	${RM} ${LIB_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}
	${RM} ${MLX}

re : fclean all

.PHONY : clean