#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egillesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 11:04:32 by egillesp          #+#    #+#              #
#    Updated: 2021/01/04 16:40:55 by egillesp         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HD = libftprintf.h
RM = rm -f

SRCSP = ./printfsrc/ft_printf.c \
		./printfsrc/fts_bonus.c \
		./printfsrc/fts_conv.c \
		./printfsrc/fts_conv_apply.c

SRCSL = ./libftsrc/ft_bzero.c \
		./libftsrc/ft_c_to_str.c \
		./libftsrc/ft_calloc.c \
		./libftsrc/ft_elementof.c \
		./libftsrc/ft_insertstr.c \
		./libftsrc/ft_isdigit.c \
		./libftsrc/ft_itoa_base.c \
		./libftsrc/ft_itoa_basep.c \
		./libftsrc/ft_putchar_fd.c \
		./libftsrc/ft_putstr_fd.c \
		./libftsrc/ft_strdup.c \
		./libftsrc/ft_strjoin.c \
		./libftsrc/ft_strlcpy.c \
		./libftsrc/ft_strlen.c

OBJSP = ${SRCSP:.c=.o}
OBJSL = ${SRCSL:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): ${OBJSP} ${OBJSL} ${HD}
	ar rcs ${NAME} ${OBJSP} ${OBJSL}

clean:
	$(RM) $(OBJSP) $(OBJSL)

fclean: clean
	$(RM) $(NAME)

bonus: ${OBJSP} ${OBJSL} ${HD}
	ar rcs ${NAME} ${OBJSP} ${OBJSL}

re: fclean all

.PHONY: all clean fclean re bonus