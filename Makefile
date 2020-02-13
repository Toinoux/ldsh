CC		=	gcc

NAME		=	ldsh

RM		=       rm -rf

CFLAGS		+=	-W -Wextra -Wall


SRCS		=       src/main.c	\
					src/container/container.c	\
					src/functions_check/input.c	\
					src/engine/engine.c			\
					src/parsing/parser_cmd.c

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
		@printf "[\033[0;32mdone\033[0m] % 33s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS) -I includes

all:            core

core:		$(NAME)

$(NAME):        $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I includes/
		@printf "[\033[0;32mcompilation completed\033[0m] % 33s\n" $<

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS)
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
