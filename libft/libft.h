/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:09:23 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/29 18:49:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_countword(char const *s, char c);
int					ft_wordlen(char const *s, char c);
char				*ft_getword(char const *s, char c);
char const			*ft_skipc(char const *s, char c);
char const			*ft_skiptoc(char const *s, char c);
int					ft_numlen(long long n);
int					ft_power(int base, int power);
char				*ft_itoa_base(size_t n, char *base);
char				*ft_strfreecat_back(char **str1, char *str2);
char				*ft_strfreecat_front(char **str1, char *str2);
char				*ft_strfncat_back(char **str1, char *str2,
						size_t len1, size_t len2);
char				*ft_strfncat_front(char **str1, char *str2,
						size_t len1, size_t len2);
void				ft_putstr_len(char *str, size_t len);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstpushback(t_list **alst, t_list *new);
void				ft_lstprint(t_list *lst);
t_list				*ft_lstsearch(t_list *lst, char *str);
void				ft_lstrev(t_list **lst);

typedef struct		s_stack
{
	struct s_list	*head;
	size_t			size;
	size_t			content_size;
}					t_stack;

t_stack				*ft_stack_create(size_t content_size);
void				ft_stack_push(t_stack *stack, void const *content);
void				*ft_stack_pop(t_stack *stack);

typedef struct		s_queue
{
	struct s_list	*head;
	struct s_list	*tail;
	size_t			size;
	size_t			content_size;
}					t_queue;

t_queue				*ft_queue_create(size_t content_size);
void				ft_queue_enqueue(t_queue *queue, void const *content);
void				*ft_queue_dequeue(t_queue *queue);

typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

t_node				*ft_node_create(void *content);
void				ft_node_push_front(t_node **node, t_node *new);
void				ft_node_push_back(t_node **node, t_node *new);
void				*ft_node_pop_front(t_node **node);
void				ft_node_delete(t_node *node, void (*del)(void *));
size_t				ft_node_len(t_node *node);

#endif

