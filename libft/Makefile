# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 15:23:09 by mbaumgar          #+#    #+#              #
#    Updated: 2024/05/14 13:12:25 by mbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./libft.a

# ╔═╗╦  ╔═╗╔═╗╔═╗
# ╠╣ ║  ╠═╣║ ╦╚═╗
# ╚  ╩═╝╩ ╩╚═╝╚═╝
ifeq ($(shell uname), Linux)
CFLAGS	= -Wall -Werror -Wextra -g3
else
CFLAGS	= -g3
endif
ARFLAGS = -crs
RM		= rm -rf

# ╔═╗╔═╗╦  ╔═╗╦═╗╔═╗
# ║  ║ ║║  ║ ║╠╦╝╚═╗
# ╚═╝╚═╝╩═╝╚═╝╩╚═╚═╝
GREEN	= \033[1;32m# bold / green
RED		= \033[1;31m# bold / red
END		= \033[m# remove style

# ╔═╗╔═╗╦ ╦╦═╗╔═╗╔═╗╔═╗
# ╚═╗║ ║║ ║╠╦╝║  ║╣ ╚═╗
# ╚═╝╚═╝╚═╝╩╚═╚═╝╚═╝╚═╝

SRC_DIR	= ./src/
OUT_DIR	= ./bin/

SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c	ft_memcpy.c ft_memmove.c ft_abs.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
		ft_nlen_base.c ft_nlen_ubase.c ft_strdup_array.c ft_int_ovcheck.c \
		ft_free_tab.c ft_free_strjoin.c ft_issign.c ft_isspace.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsplit.c ft_printf.c \
		pf_arg_char.c pf_arg_int.c pf_arg_str.c pf_arg_ptr.c \
		pf_arg_hex.c pf_arg_uint.c pf_arg_pcent.c
		
OBJ		= ${SRC:%.c=${OUT_DIR}%.o}

# ╦═╗╦ ╦╦  ╔═╗╔═╗
# ╠╦╝║ ║║  ║╣ ╚═╗
# ╩╚═╚═╝╩═╝╚═╝╚═╝

all: ${NAME}

${NAME}: ${OBJ}
	@${AR} ${ARFLAGS} ${NAME} ${OBJ} 

${OUT_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OUT_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OUT_DIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all

uwu: re
	@${MAKE} clean --no-print-directory

.PHONY: all clean fclean re uwu
