/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:49:01 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 15:49:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/libft.h"

enum {
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10
};

typedef struct s_stack
{
    int	size;
    int	*arr;
}				t_stack;

void	ft_operation(t_stack *a, t_stack *b, int operation);
int		*ft_parse_args(int ac, char **av);
char	**ft_read_input(void);
int		ft_exec_instructions(t_stack *stack, char **ins);

#endif