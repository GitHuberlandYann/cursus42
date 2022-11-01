/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:39:51 by yhuberla          #+#    #+#             */
/*   Updated: 2022/10/30 14:38:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int	s_size;
	int	nb_s;
	int	r;
	int	rr;
}				t_stack;

void	ft_compute(t_stack *a, t_stack *b);
int		ft_stack_sorted(t_stack *stack);
void    ft_sort_small(t_stack *a, t_stack *b);
void	ft_sort_big(t_stack *a, t_stack *b);

void	ft_sort_no_b(t_stack *a);
void	ft_sort_selection(t_stack *a, t_stack *b);
void	ft_sort_bubble(t_stack *a);
void	ft_sort_insertion(t_stack *a, t_stack *b);
void    ft_sort_section_selection(t_stack *a, t_stack *b, int base);
void    ft_sort_section_insertion(t_stack *a, t_stack *b, int base);
void	ft_sort_insertion_big(t_stack *a, t_stack *b, int section);

void	ft_display_stack(t_stack stack);

void	ft_operation(t_stack *a, t_stack *b, int operation);
void	ft_rot_big(t_stack *stack, int ope);

#endif
