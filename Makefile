# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 09:06:04 by lfrederi          #+#    #+#              #
#    Updated: 2022/10/14 12:48:54 by lfrederi         ###   ########.fr        #
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

SRCS	= 	sources/main.c \
			sources/Parsing/check_cub.c \
			sources/Parsing/map.c \
			sources/Parsing/open_file.c \
			sources/Parsing/parsing_error.c \
			sources/Parsing/parsing.c \
			sources/Parsing/texture_rgb.c \
			sources/Parsing/utils.c \
			sources/Parsing/valid_map.c \
			sources/Parsing/valid_walls.c \
			sources/Parsing/missing_info.c \
			sources/Parsing/utils_2.c\
			$(addprefix sources/Raycasting/, init.c raycasting.c \
			$(addprefix draw/, draw_minimap.c draw_rectangle.c draw_segment.c draw_wall.c)\
			$(addprefix event/, init.c action.c move_dir.c move_player.c press_esc.c display_minimap.c)\
			$(addprefix utils/, error.c utils_math.c utils_map.c clear.c create_img.c))

HEADERS = 	includes/Cub3D.h \
			includes/Parsing.h \
			includes/Raycasting.h

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

DIR_H_PROJECT	= includes/
DIR_H_LIBFT		= libft/headers/
DIR_H_MLX		= minilibx/
IFLAGS 			= -I ${DIR_H_PROJECT} -I ${DIR_H_LIBFT} -I ${DIR_H_MLX}

DIR_LIBMLX 	= minilibx/
DIR_LIBFT	= libft/
DIR_LIBEXT 	= /usr/include/../lib/

LIBRARY	= -L ${DIR_LIBFT} -lft -L ${DIR_LIBMLX} -lmlx -L ${DIR_LIBEXT} -lXext 
LIBFLAG = -lX11 -lm

NAME		= cub3d
NAME_BONUS	= cub3d_bonus

CC		= cc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g

$(OBJS_PATH)%.o: %.c ${HEADERS}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

all: libft_make minilibx_make ${NAME}

${NAME}: ${OBJS} ${HEADERS}
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

bonus: fclean libft_make minilibx_make ${OBJS} ${HEADERS}
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	
	@${CC} ${CFLAGS} ${OBJS} ${LIBRARY} ${LIBFLAG} -o ${NAME_BONUS}
	@printf "\n${_GREEN}${_BOLD}${NAME} OK${_END}\n"

clean:
	@${RM} ${OBJS}
	@$(RM) $(OBJS_PATH)

fclean:	clean libft_clean minilibx_clean
	@${RM} ${NAME} ${NAME_BONUS} 

re:		fclean all

.PHONY:	all clean fclean re libft_make libft_clean minilibx_clean minilibx_make bonus
