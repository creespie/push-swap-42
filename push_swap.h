#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "libft/libft.h"

typedef struct		s_stack
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_stack;

#endif