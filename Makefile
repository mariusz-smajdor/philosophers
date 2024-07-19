NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm

SRCS = philo.c init_data/index.c init_data/inline_functions.c start_sim/index.c \
		safe_functions.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -pthread -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

.PHONY: all clean fclean re