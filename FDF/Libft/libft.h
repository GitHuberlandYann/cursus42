/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:41:03 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/19 14:30:00 by marvin           ###   ########.fr       */
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

int	    ft_atoi(const char *str);
int     ft_arraylen(char **array);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char **str);
char	*ft_strcpy_from_nl(char **str);
char	*ft_strcpy_until_nl(char *str);
char	**ft_split(char const *s, char c);
void	ft_fill_tab(int *tab, int nb, ...);

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
	void			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);

#endif
