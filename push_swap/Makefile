FLAGS= -Wall -Wextra -Werror -I.
CC= cc
NAME= push_swap
SRCS= $(wildcard *.c)
BONUS= $(wildcard ./bonus/*.c)
RM= rm -f
OBJS= $(SRCS:.c=.o)
BONUS_OBJS= $(BONUS:.c=.o)
BONUS_NAME= checker


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) ${FLAGS} ${OBJS} -o ${NAME}

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re