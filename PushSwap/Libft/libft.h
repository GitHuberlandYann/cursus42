/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:41:03 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/14 22:28:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int nb);

long	ft_atoi(const char *str);
void	ft_arrayset(int *tab, int value, int size);
int		ft_arraylen(char **array);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char **str);
char	*ft_strcpy_from_nl(char **str);
char	*ft_strcpy_until_nl(char *str);
char	**ft_split(char const *s, char c);

void	ft_printf(const char *str, ...);
int		ft_abs(int nb);
int		ft_nbrlen(int nb);
char	ft_get_type(char c);
void	ft_putchar(unsigned char c);
void	ft_putchars(unsigned char c, int size);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putunbr(unsigned int nb);
void	ft_puthexa(unsigned int nb, int upper);
void	ft_putaddresshexa(void *ptr);

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(int content);

#endif
