NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  libft.c \
		  ft_list.c \
		  ft_checks.c \
		  ft_array.c \
		  ft_swap.c \
		  ft_push.c \
		  ft_rotate.c \
		  ft_reverse_rotate.c \
		  ft_find.c \
		  ft_position.c \
		  ft_find_spot_b.c \
		  ft_find_spot_a.c \
		  ft_compare.c \
		  ft_fastest.c \
		  ft_execute.c \
		  ft_free.c \
		  ft_insert_sort.c \
		  ft_chunk_sort.c \
		  ft_bench_updater.c \
		  ft_sort.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
