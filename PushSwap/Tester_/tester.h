/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:12:33 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 11:12:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

#include "../SRCS/push_swap.h"
#include <fcntl.h>
#include <stdarg.h>

typedef struct s_parse
{
	char	**arr;
	int		wc;
}				t_parse;

t_parse	*ft_read_output(void);

#endif