# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 12:25:15 by marvin            #+#    #+#              #
#    Updated: 2024/11/14 12:25:15 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line.c 

NAME = get_next_line.a
PRIC = ar rcs
RM = rm -f 
OBJS = $(SRCS:.c=.o)
${NAME}:${OBJS}
		${PRIC} ${NAME} ${OBJS}
%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@
all:${NAME}
clean:
		${RM} ${NAME}
fclean: clean
		${RM} ${NAME}
re: fclean all
.PHONY : all clean fclean re