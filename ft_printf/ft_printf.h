/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:01:09 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/25 12:26:04 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_res
{
	int	count;
	int	error;
}				t_res;

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
int		ft_abs(int nb);
char	ft_get_type(char c);
void	ft_putchar(unsigned char c, t_res *res);
void	ft_putstr(char *str, t_res *res);
void	ft_putnbr(int nb, t_res *res);
void	ft_putunbr(unsigned int nb, t_res *res);
void	ft_puthexa(unsigned int nb, int upper, t_res *res);
void	ft_putaddresshexa(void *ptr, t_res *res);

#endif
