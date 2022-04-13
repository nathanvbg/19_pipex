NAME	= pipex

SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${OBJS} ${CFLAGS} ./libft/libft.a -o ${NAME}

clean:
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard *.c} ${wildcard *.h} ${wildcard libft/*.c} ${wildcard libft/*.h}

bonus: all

.PHONY: clean fclean re all bonus norme