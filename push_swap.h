#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "libft/libft.h"

typedef struct		s_list
{
	void			*content;
	void			*order;
	struct s_list	*next;
}					t_list;

#endif