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
void	ft_test_case(t_stack *a, int section);
void	ft_test_case_small(t_stack *a);
int		ft_load_test_big(t_stack *a, int nb);
int		ft_load_test_small(t_stack *a, int nb);

#endif