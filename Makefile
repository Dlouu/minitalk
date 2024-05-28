# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 13:28:40 by mbaumgar          #+#    #+#              #
#    Updated: 2024/05/28 15:39:49 by mbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT			= client
NAME_SERVER 		= server

LFT					= ./libft/libft.a
LIBFT				= ./libft
MAKE_LIBFT			= ${MAKE} --no-print-directory -C ${LIBFT}

# ╔═╗╦  ╔═╗╔═╗╔═╗
# ╠╣ ║  ╠═╣║ ╦╚═╗
# ╚  ╩═╝╩ ╩╚═╝╚═╝

CC					= cc
ARFLAGS 			= -crs
RM					= rm -rf
CFLAGS				= -Wall -Werror -Wextra
DEBUG				= -fsanitize=address -fsanitize=leak -g3

# ╔═╗╔═╗╦  ╔═╗╦═╗╔═╗
# ║  ║ ║║  ║ ║╠╦╝╚═╗
# ╚═╝╚═╝╩═╝╚═╝╩╚═╚═╝

YELLOW				= \033[1;33m# bold / yellow
RED					= \033[1;31m# bold / red
BACKGROUND			= \033[7;33m# background / yellow
BLINK				= \033[5;2;39m# blink / gray
END					= \033[m# remove style

# ╔═╗╔═╗╦ ╦╦═╗╔═╗╔═╗╔═╗
# ╚═╗║ ║║ ║╠╦╝║  ║╣ ╚═╗
# ╚═╝╚═╝╚═╝╩╚═╚═╝╚═╝╚═╝

SRC_DIR				= src/
OUT_DIR				= bin/

SRC_CLIENT			= client.c utils.c
SRC_SERVER			= server.c utils.c

OBJ_CLIENT			= ${SRC_CLIENT:%.c=${OUT_DIR}%.o}
OBJ_SERVER			= ${SRC_SERVER:%.c=${OUT_DIR}%.o}

# ╦═╗╦ ╦╦  ╔═╗╔═╗
# ╠╦╝║ ║║  ║╣ ╚═╗
# ╩╚═╚═╝╩═╝╚═╝╚═╝

all: ${NAME_CLIENT} ${NAME_SERVER}

minitalk: ${NAME_CLIENT} ${NAME_SERVER}

${LFT}: 
	@${MAKE_LIBFT}

${NAME_CLIENT}: ${LFT} ${OBJ_CLIENT}
	@${CC} ${CFLAGS} -o ${NAME_CLIENT} ${OBJ_CLIENT} ${LFT}
	@echo "\n ${YELLOW}minitalk client${END} is ready..."

${NAME_SERVER}: ${LFT} ${OBJ_SERVER}
	@${CC} ${CFLAGS} -o ${NAME_SERVER} ${OBJ_SERVER} ${LFT}
	@echo " ${YELLOW}minitalk server${END} is ready ᕙ ( •̀ ᴗ •́ )ᕗ\n"

${OUT_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OUT_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${MAKE_LIBFT} clean
	@echo "🧹 ${RED}removed:${END} libft objects"
	@${RM} ${OUT_DIR}
	@echo "🧹 ${RED}removed:${END} minitalk objects"

fclean: clean
	@${MAKE_LIBFT} fclean
	@echo "🧹 ${RED}removed:${END} libft archive"
	@${RM} ${NAME_CLIENT} ${NAME_SERVER} ${BONUS_NAME_CLIENT} ${BONUS_NAME_SERVER}
	@echo "🧹 ${RED}removed:${END} minitalk client and/or server\n\
	 ${BACKGROUND} Everything has been DESTROYED!! ${END} ( •̀ ᴖ •́ )\n"

re: fclean all

uwu: re
	@${MAKE} --no-print-directory clean

norminette:
	norminette libft/src/*
	@echo "\n"
	@norminette libft/inc/*
	@echo "\n"
	norminette inc/*
	@echo "\n"
	norminette src/*

sanitize: re
	${CC} ${CFLAGS} ${DEBUG} -o ${NAME_CLIENT} ${OBJ_CLIENT} ${LFT}
	${CC} ${CFLAGS} ${DEBUG} -o ${NAME_SERVER} ${OBJ_SERVER} ${LFT}

git: fclean
	git add .
	git commit -m "update from minitalk : ${m}"
	git push

.PHONY: all clean fclean re minitalk uwu norminette sanitize git
