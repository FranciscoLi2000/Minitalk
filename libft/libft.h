/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:13:34 by yufli             #+#    #+#             */
/*   Updated: 2025/06/06 22:36:05 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// Linked list structure
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

// Function prototypes (add/remove as needed)
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	lcm(unsigned int a, unsigned int b);
unsigned char	reverse_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char octet);
int				ft_atoi(char *str);
void			ft_bzero(void *s, unsigned int n);
void			*ft_calloc(unsigned int nmemb, unsigned int size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *str1, const void *str2, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memset(void *s, int c, unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);

// Bonus part (linked list)
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// The functions of Exam Rank 2
int				ft_atoi_base(const char *str, int str_base);
int				ft_is_prime(int nbr);
int				ft_isspace(int c);
char			*ft_itoa(int n);
int				*ft_range(int start, int end);
int				*ft_rrange(int start, int end);
char			**ft_split(char const *s, char c);
char			*ft_strcat(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strcspn(const char *s, const char *reject);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strpbrk(const char *s1, const char *s2);
char			*ft_strrev(char *str);
size_t			ft_strspn(const char *s, const char *accept);
char			*ft_strstr(char *str, char *to_find);
void			ft_swap(int *a, int *b);
int				is_power_of_2(unsigned int n);
int				max(int *tab, unsigned int len);
void			print_bits(unsigned char octet);
void			ft_list_foreach(t_list *begin_list, void (*f)(void *));
void			ft_list_remove_if(t_list **begin_list,
					void *data_ref, int (*cmp)());
void			sort_int_tab(int *tab, unsigned int size);
t_list			*sort_list(t_list *lst, int (*cmp)(int, int));

#endif
