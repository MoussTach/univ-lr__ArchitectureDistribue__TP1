CC	= gcc

RM	= rm -f

NAME	= tp1

SRC:= $(shell find src -type f -name "*.c")


OBJ	= $(SRC:.c=.o)

CFLAGS	= -W -Wall -Wextra -fopenmp

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all