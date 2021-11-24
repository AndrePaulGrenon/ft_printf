SRCS	= ft_printf.c ft_printf_utils.c ft_hexa.c ft_give_adress.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra -g 

.c.o :	
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc libftprintf.a ${OBJS}
			ranlib libftprintf.a

all : 		${NAME}

clean :
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		fclean all clean re
