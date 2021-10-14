# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 12:58:34 by cfico-vi          #+#    #+#              #
#    Updated: 2021/10/13 20:37:29 by cfico-vi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft.a

LIBFT_PATH	= ./libft/

SRC			= ./source
MAIN		= ${SRC}/main
OPS			= ${SRC}/operations

MAIN_F		= ${MAIN}/push_swap_0.c ${MAIN}/sort_stacks_0.c
MAIN_OBJ	= push_swap_0.o sort_stacks_0.o
OPS_F		= ${OPS}/del_0.c ${OPS}/exit_0.c ${OPS}/check_sort_0.c ${OPS}/parse_0.c ${OPS}/print_steps_0.c ${OPS}/sort_array_0.c ${OPS}/commands_0.c ${OPS}/commands_1.c
OPS_OBJ		= del_0.o exit_0.o check_sort_0.o parse_0.o print_steps_0.o sort_array_0.o commands_0.o commands_1.o

CC			= clang
CFLAGS		= -g -Wall -Werror -Wextra
LIB_FLAGS	= -lft
RM			= rm -f

all:		${NAME}

${NAME}: 	${MAIN_OBJ} ${OPS_OBJ} $(LIBFT)
			@echo making "push_swap"...
			@${CC} ${CFLAGS} -o ${NAME} ${MAIN_OBJ} ${OPS_OBJ} -L ${LIBFT_PATH} ${LIB_FLAGS}
			@echo "\033[92mall done!\033[0m"
			@echo "\033[92mrun './push_swap' with a well formatted list of numbers.\033[0m"
			@echo "\033[92mit will give you a list of instructions for sorting it.\033[0m"
			@echo "\033[92mhope you like it!\033[0m"

${LIBFT}:
			@echo making libft.......
			@echo ...................
			@make --no-print-directory -C ${LIBFT_PATH}
			@echo done!

${MAIN_OBJ}: ${MAIN_F}
			@${CC} ${CFLAGS} -g -c ${MAIN_F}

${OPS_OBJ}: ${OPS_F}
			@${CC} ${CFLAGS} -g -c ${OPS_F}

clean:
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			${RM} ${MAIN_OBJ} ${OPS_OBJ}

fclean:		clean
			@echo cleaning!
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			${RM} ${NAME}
			@echo cleaned!

re:			fclean all

git:
			git add .
			git commit -m "$m"
			git push

.PHONY:		all clean fclean re
