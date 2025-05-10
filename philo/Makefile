TARGET = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	./mandatory/$(TARGET).c \
		./utils/ft_error.c \
		./utils/ft_atoi.c \
		./utils/ft_check_args.c \
		./utils/ft_mutex.c \
		./utils/my_malloc.c \
		./utils/ft_init.c \
		./utils/ft_printer.c \
		./utils/setsGets.c \
		./utils/end_checkers.c \
		./utils/ft_eat.c \

RM = rm -rf
NAME = $(TARGET).a
OBJS = $(SRCS:.c=.o)
HEADER = ./includes/$(TARGET).h

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(TARGET)

$(TARGET): $(NAME) $(HEADER)
	@echo "$(BLUE)Making $(TARGET) ...$(DEF_COLOR)"
# @sleep 1
	@${CC} ${CFLAGS} -o $(TARGET) ./mandatory/$(TARGET).c $(NAME) -lpthread
	@echo "$(GREEN)  _____  _     _   _                       _               "
	@echo "$(GREEN) |  __ \| |   |_| | |                     | |              "
	@echo "$(GREEN) | |__\ | |__  _  | | ___  ___  ___  _ __ | |__   ___ _ __ "
	@echo "$(GREEN) |  ___/| '_ \| | | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__|"
	@echo "$(GREEN) | |    | | | | | | | \_\ \__ \ \_\ | |_\ | | | |  __/ |   "
	@echo "$(GREEN) |_|    |_| |_|_| |_|\___/|___/\___/| .__/|_| |_|\___|_|   "
	@echo "$(GREEN)                                  | |                      "
	@echo "$(GREEN)                                  |_|                      "
	@echo "$(GREEN)\n==The Executable of [$(TARGET)] has been compiled!==\n$(DEF_COLOR)"
	@echo "$(YELLOW)\n=> Usage: \n./$(TARGET) number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat\n$(DEF_COLOR)"

$(NAME): $(OBJS)
	@echo "$(BLUE)Archiving the Library $(NAME) ...$(DEF_COLOR)"
# @sleep 1
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@echo "$(BLUE)Compiling $< ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(TARGET)

re: fclean all

.PHONY: clean
