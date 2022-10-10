
_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m


SRCS	= 	$(addprefix srcs/ft_ctype/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c)\
			$(addprefix srcs/ft_mem/, ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c)\
			$(addprefix srcs/ft_string/, ft_strlen.c ft_strlcpy.c ft_strlcat.c\
										ft_toupper.c ft_tolower.c\
										ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_strnstr.c\
										ft_atoi.c ft_atol.c ft_itoa.c\
										ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_clear_split.c\
										ft_strmapi.c ft_striteri.c)\
			$(addprefix srcs/ft_stdio/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
										get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
										printf/ft_print_flags.c printf/ft_print_flags1.c printf/ft_putnbr.c\
										printf/ft_putstr.c printf/ft_utils.c printf/ft_utils1.c printf/ft_utils2.c\
										printf/ft_printf.c)\
			$(addprefix srcs/ft_lst/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			 						  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

HEADER	= ./headers/

OBJS_PATH = objs/
OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

NAME	= libft.a

CC		= cc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

$(OBJS_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"

${NAME}:	${OBJS}
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@ar rcs ${NAME} ${OBJS}
	@printf "\n${_GREEN}${_BOLD}Libft OK${_END}\n"
clean:
	@${RM} ${OBJS} 

all:	${NAME}

fclean:	clean
	@${RM} ${NAME} ${OBJS_PATH}

re:		fclean all

.PHONY:	all clean fclean re
