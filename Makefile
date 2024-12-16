CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a
HEADERS = ft_printf.h
SRCS = ft_transl_no.c ft_transl_chars.c ft_transl_digits.c ft_transl_udigits.c \
	   t_print.c ft_printf.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	ar rcs ${LIBFT} ${OBJS}
	mv ${LIBFT} ${NAME}

%.o: %.c ${HEADES}
	${CC} ${CFLAGS} -c $< -o $@
	
${LIBFT}:
	make -C ./libft

clean: 
	rm -rf ${OBJS} && make -C ./libft clean

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT}

re: fclean all
