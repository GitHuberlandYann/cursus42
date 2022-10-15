/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:15:31 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/15 16:37:34 by yhuberla         ###   ########.fr       */
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
	int		arglen;
	char	type;
	int		int_copy;
	int		space;
	int		hashtag;
	int		plus;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	va_list	*ap;
}				t_parse;

void	ft_putchar_fd(char c, int fd, int *res);

#endif