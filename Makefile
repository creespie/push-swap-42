NAME	= push_swap
BONUS	= checker

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  libft.c \
		  libft_printf.c \
		  ft_flags.c \
		  ft_main_utils.c \
		  ft_bench_print.c \
		  ft_bench_write.c \
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
		  ft_sort.c \
		  ft_sort_two.c \
		  ft_sort_big.c \

BONUS_SRCS = checker.c \
			libft.c \
			libft_printf.c \
			ft_flags.c \
			ft_main_utils.c \
			ft_bench_print.c \
			ft_bench_write.c \
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
			ft_sort.c \
			ft_sort_two.c \
			ft_sort_big.c \
			checker_helpers.c \
			checker_rotate.c \
			checker_utils.c \
			get_next_line.c \
			get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.bo)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c push_swap.h libft.h
	$(CC) $(CFLAGS) -c $< -o $@

%.bo: %.c push_swap.h libft.h get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
