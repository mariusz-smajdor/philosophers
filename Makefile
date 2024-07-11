NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm

SRCS = philo.c init_simulation.c start_simulation.c utils.c safe_functions.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -pthread -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	re: fclean all

.PHONY: all clean fclean re