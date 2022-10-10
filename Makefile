# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 09:06:04 by lfrederi          #+#    #+#              #
#    Updated: 2022/09/28 16:38:15 by lfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m

SRCS	= $(addprefix sources/, main.c)\
		  $(addprefix sources/mlx/, init.c)\
		  $(addprefix sources/image/, create.c put_pixel.c)\
		  $(addprefix sources/event/, init.c action.c move_player.c move_view.c press_esc.c)\
		  $(addprefix sources/player/, init.c draw.c)\
		  $(addprefix sources/utils/, utils.c draw_segment.c draw_rectangle.c draw_map.c)\
		  $(addprefix sources/raycasting/, raycasting.c)


HEADERS = $(addprefix includes/, init.h struct.h event.h image.h player.h utils.h raycasting.h)

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DIR_H_PROJECT	= includes/
DIR_H_LIBFT		= libft/headers/
DIR_H_MLX		= minilibx/
IFLAGS 			= -I ${DIR_H_PROJECT} -I ${DIR_H_LIBFT} -I ${DIR_H_MLX}

DIR_LIBMLX 	= minilibx/
DIR_LIBFT	= libft/
DIR_LIBEXT 	= /usr/include/../lib/

LIBRARY	= -L ${DIR_LIBMLX} -lmlx -L ${DIR_LIBEXT} -lXext  -L ${DIR_LIBFT} -lft
LIBFLAG = -lX11 -lm

NAME	= cub3d

CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g

${OBJS_PATH}%.o: %.c ${HEADERS}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

all: libft_make minilibx_make ${HEADERS} ${NAME}

${NAME}: ${OBJS}
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	
	@${CC} ${CFLAGS} ${OBJS} ${LIBRARY} ${LIBFLAG} -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}${NAME} OK${_END}\n"

libft_make: 
	@make --no-print-directory -C ${DIR_LIBFT}
libft_clean:
	@make --silent fclean -C ${DIR_LIBFT}
minilibx_make:
	@make --silent -C ${DIR_LIBMLX}
minilibx_clean:
	@make --silent clean -C ${DIR_LIBMLX}

clean:
	@${RM} ${OBJS}
	@$(RM) $(OBJS_PATH)

fclean:	clean libft_clean minilibx_clean
	@${RM} ${NAME} ${BONUS} 

re:		fclean all

.PHONY:	all clean fclean re libft_make libft_clean minilibx_clean minilibx_make
