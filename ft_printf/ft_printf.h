/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:02 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/07 11:02:02 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_nbrlen(int nb);
int		ft_unbrlen(unsigned int nb, int base);
int		ft_lb2_printf_char(char c, int *res, int result);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd, int *res); //deletethis
void	ft_putstr_fd(char *s, int fd); //deletethis
void	ft_putnbr_fd(long n, int fd, int *res); //deletethis
void	ft_printf_char(int c, int *res);
void	ft_printf_string(char *str, int *res);
void	ft_printf_address(void *ptr, int *res);
void	ft_convert_address_to_hexa(unsigned long nb, int *res);
void	ft_printf_decimal(int nb, int *res);
void	ft_printf_int(int nb, int *res);
void	ft_printf_unsigned_int(unsigned int nb, int *res);
void	ft_printf_hexa_lower(unsigned int nb, int *res);
void	ft_printf_hexa_upper(unsigned int nb, int *res);
void	ft_printf_percent(int *res);
void	ft_loop_bonus_width(const char *str, int *index, int *res, va_list ap);
void	ft_loop_bonus2(const char *str, int *index, int *res, va_list ap);

#endif