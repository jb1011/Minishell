# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgelinet <lgelinet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 11:29:17 by user42            #+#    #+#              #
#    Updated: 2021/06/08 12:06:54 by lgelinet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c 

CC = gcc

${OBJ}: ${FILES}
	${CC} ${FLAGS} ${FILES}

FILES =	ft_chr.c \
		ft_is.c \
		ft_maths.c \
		ft_mem.c \
		ft_memchg.c \
		ft_put.c \
		ft_set.c \
		ft_split.c \
		ft_str.c \
		ft_strchg.c \
		ft_strm.c \
		inttab.c \
		get_next_line.c \
		ft_is2.c \
		ft_maths2.c \
		list.c

OBJ = ${FILES:%.c=%.o}

${NAME} : ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

INC		= -I includes/

%.o: %.c
				$(CC) ${INC} -o $@ -c $?

all :	${NAME}


clean : 
	rm -f ${OBJ}

fclean : clean 
	rm -f ${NAME}

re : fclean all

.PHONY: fclean clean re
