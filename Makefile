# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egillesp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 11:04:32 by egillesp          #+#    #+#              #
#    Updated: 2020/12/18 16:23:49 by egillesp         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
HD = libftprintf.h
RM = rm -f

SRCSP = $(wildcard printfsrc/*.c)
SRCSL = $(wildcard libftsrc/*.c)

OBJSP = ${SRCSP:.c=.o}
OBJSL = ${SRCSL:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): ${OBJSP} ${OBJSL}
	ar rcs ${NAME} ${OBJSP} ${OBJSL}

clean:
	$(RM) $(OBJSP) $(OBJSL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
