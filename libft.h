// libft.h
#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_isdigit(int c);
int		ft_atoi_safe(const char *str, int *out);
void	*ft_memset(void *s, int c, size_t n);
int		ft_dprintf(int fd, const char *format, ...);

#endif