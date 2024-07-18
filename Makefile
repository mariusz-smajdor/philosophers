NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm

SRCS = philo.c initiate_data.c start_simulation.c \
		utils/generic.c utils/getters_setters.c utils/inline.c utils/safe.c
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