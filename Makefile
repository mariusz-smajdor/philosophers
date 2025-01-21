NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -O3 -pthread
RM = rm -f

SRCS = philo.c init_data/index.c init_data/inline_functions.c \
		start_sim/index.c start_sim/philo_routine.c start_sim/monitor.c \
		clear_data.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
