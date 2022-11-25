/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:18:10 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 12:34:26 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FB_PRINTF_BONUS_H
# define FB_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_res
{
	int	count;
	int	error;
}				t_res;

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
void	ft_putchar(unsigned char c, t_res *res);
void	ft_putstr(char *str, int size, t_res *res);
void	ft_putnbr(int nb, t_res *res);
void	ft_putunbr(unsigned int nb, t_res *res);
void	ft_puthexa(unsigned int nb, int upper, t_res *res);
void	ft_putaddresshexa(void *ptr, t_res *res);
void	ft_putchars(unsigned char c, int count, t_res *res);
void	ft_reset_parsing(t_parse *current);
void	ft_parse_bonus2(const char *str, int start, int end, t_parse *current);

#endif
