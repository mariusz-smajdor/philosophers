NAME = philo.exe
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = del

SRCS = philo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	re: fclean all

.PHONY: all clean fclean re