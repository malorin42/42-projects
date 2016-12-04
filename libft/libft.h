/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malorin <malorin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:14:29 by malorin           #+#    #+#             */
/*   Updated: 2016/01/25 14:57:04 by malorin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>

# define BUFF_SIZE 2

# define TG(t,b,i)		(*(t*)(((t_tab*)b)->data + (((t_tab*)b)->size * (i))))

typedef struct		s_tab
{
	unsigned char	*data;
	int				length;
	int				bytes;
	int				alloc_bytes;
	int				size;
}					t_tab;

typedef struct		s_buff
{
	char			*data;
	int				i;
	int				length;
}					t_buff;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int c);
void				ft_putendl(char const *str);
int					ft_cherchc(char const *str, char c);
char				*ft_strcat(char *str1, const char *str2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
size_t				ft_strclen(const char *str, char c);
char				*ft_strstr(char *str, const char *substr);
char				*ft_strnstr(char *str, const char *substr, size_t len);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isimpair(int c);
int					ft_ispair(int c);
char				*ft_rot13(char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_strnclr(char *s, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_math(int number, unsigned int addnum, char sign);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
int					get_next_line(const int fd, char **line);
double				ft_parse_double(t_buff *buff);
t_tab				*ft_tab_new(int size);
void				ft_tab_add(t_tab *tab, const void *add);
void				ft_tab_ini(t_tab *tab, int size);
void				ft_tab_addn(t_tab *tab, const void *add, int n);
int					ft_tab_ext(t_tab *tab, int need);
void				ft_tab_kill(void *tab);


#endif
