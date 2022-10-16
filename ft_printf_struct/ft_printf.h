/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:15:31 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/16 18:17:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_parse
{
	char	type;
	int		arglen;
	int		int_copy;
	int		space;
	int		hashtag;
	int		plus;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	va_list	ap;
}				t_parse;

int		ft_printf(const char *str, ...);
int		ft_parse(const char *str, int start, t_parse *current);
int		ft_strlen(char *str);
int		ft_nbrlen(int nb);
int		ft_unbrlen(unsigned int nb, int base);
int		ft_addresslen(unsigned long nb);
int		ft_abs(int nb);
int		ft_get_end(const char *str, int index);
int		ft_arglen(char c, va_list ap);
int		ft_atoi(const char *str, int index, int end);
int		ft_check_minus(const char *str, int start, int end);
int		ft_check_zero(const char *str, int start, int end);
int		ft_check_precision(const char *str, int start, int end);
int		ft_atoi_precision(const char *str, int index, int end);
int		ft_count_front_spaces(t_parse *current);
int		ft_count_zeros(t_parse *current);
int		ft_count_back_spaces(t_parse *current);
char	ft_get_type(const char *str, int index);
void	ft_putchar_fd(unsigned char c, int fd, int *res);
void	ft_putstr_fd(char *str, int size, int fd, int *res);
void	ft_putnbr_fd(int nb, int fd, int *res);
void	ft_putunbr_fd(unsigned int nb, int fd, int *res);
void	ft_puthexa_fd(unsigned int nb, int upper, int fd, int *res);
void	ft_putaddresshexa_fd(void *ptr, int fd, int *res);
void	ft_putchars_fd(unsigned char c, int count, int fd, int *res);
void	ft_reset_parsing(t_parse *current);
void	ft_parse_bonus2(const char *str, int start, int end, t_parse *current);

#endif
