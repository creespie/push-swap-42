#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int 	ft_isalpha(int c);
int 	ft_isascii(int c);
int		ft_isdigit(int c);
int 	ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t len);
void	*ft_memset(void *s, int c, size_t size);
void	ft_putchar_fd(char c, int	fd);
void 	ft_putchar(char c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(const char*s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
char	**ft_split(char const *string, char c);
char 	*ft_strcat(char *dest, char *src);
char 	*ft_strchr(const char *s, int c);
int 	ft_strcmp(char *s1, char *s2);
char    *ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *src);
void	*ft_striter(char *s, void (*f)(char *));
void	*ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int 	ft_strncmp(char *s1, char *s2, unsigned int n);
char    *ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_tolower(char *str);
char	*ft_toupper(char *str);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif