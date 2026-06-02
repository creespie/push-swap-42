NAME	= push_swap
BONUS	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iincludes

LIBFT_SRCS = libft/libft.c \
			 libft/libft_printf.c

COMMON_SRCS = $(LIBFT_SRCS) \
			  src/init/ft_flags.c \
			  src/init/ft_flags_helper.c \
			  src/init/ft_main_utils.c \
			  src/init/ft_array.c \
			  src/checks/ft_checks.c \
			  src/stack/ft_list.c \
			  src/stack/ft_find.c \
			  src/stack/ft_position.c \
			  src/stack/ft_free.c \
			  src/operations/ft_swap.c \
			  src/operations/ft_push.c \
			  src/operations/ft_rotate.c \
			  src/operations/ft_reverse_rotate.c \
			  src/sort/ft_find_spot_b.c \
			  src/sort/ft_find_spot_a.c \
			  src/sort/ft_compare.c \
			  src/sort/ft_fastest.c \
			  src/sort/ft_execute.c \
			  src/sort/ft_insert_sort.c \
			  src/sort/ft_chunk_sort.c \
			  src/sort/ft_sort.c \
			  src/sort/ft_sort_two.c \
			  src/sort/ft_sort_big.c \
			  src/bench/ft_bench_print.c \
			  src/bench/ft_bench_write.c \
			  src/bench/ft_bench_updater.c

SRCS = src/main.c $(COMMON_SRCS)

BONUS_SRCS = src/checker/checker.c \
			 $(COMMON_SRCS) \
			 src/checker/checker_helpers.c \
			 src/checker/checker_rotate.c \
			 src/checker/checker_utils.c \
			 src/gnl/get_next_line.c \
			 src/gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.bo)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c includes/push_swap.h includes/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

%.bo: %.c includes/push_swap.h includes/libft.h includes/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
