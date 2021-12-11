/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:02:44 by bgenia            #+#    #+#             */
/*   Updated: 2021/12/11 19:32:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(
			const char *haystack,
			const char *needle,
			size_t len
			);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}	t_list;

t_list	*ft_list_create(void *value);
void	ft_list_add_front(t_list **list, t_list *element);
size_t	ft_list_size(t_list *list);
t_list	*ft_list_last(t_list *list);
void	ft_list_add_back(t_list **list, t_list *element);
void	ft_list_free(t_list *list, void (*_free)(void*));
void	ft_list_clear(t_list **list, void (*_free)(void*));
void	ft_list_for_each(t_list *list, void (*f)(void*));
t_list	*ft_list_map(t_list *list, void *(*f)(void *), void (*_free)(void *));

t_list	*ft_list_at(t_list *list, unsigned int index);
t_list	*ft_list_find(t_list *list, void *value, int (*comparator)());
void	ft_list_for_each_if(
			t_list *list,
			void (*f)(void *),
			void *value,
			int (*comparator)()
			);
t_list	*ft_list_from(int count, void **values, void (*_free)(void *));
void	ft_list_insert_after(t_list *list, t_list *element);
void	ft_list_merge(t_list **list1, t_list *list2);
void	ft_list_remove_if(
			t_list **list,
			void *value,
			int (*comparator)(),
			void (*_free)(void *)
			);
void	ft_list_reverse_values(t_list *list);
void	ft_list_reverse(t_list **list);
void	ft_list_sort(t_list **list, int (*comparator)());
void	ft_list_swap_elements(
			t_list **list,
			unsigned int index1,
			unsigned int index2
			);
void	ft_list_swap_values(
			t_list *list,
			unsigned int index1,
			unsigned int index2
			);
void	ft_list_sorted_insert(t_list **list, void *value, int (*comparator)());
void	ft_list_sorted_merge(
			t_list **list1,
			t_list *list2,
			int (*comparator)()
			);

#endif
