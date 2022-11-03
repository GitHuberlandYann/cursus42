/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <yhuberla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:17:43 by yhuberla          #+#    #+#             */
/*   Updated: 2022/11/02 13:17:43 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

enum {
	S = 0,
	P = 1,
	R = 2,
	RR = 3
};

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	r;
	int	rr;
}				t_stack;

int		*ft_parse_args(int *ac, char **av);
void	ft_compute(t_stack *a, t_stack *b);
void	ft_sort_big(t_stack *a, t_stack *b);
void	ft_sort_small(t_stack *a, t_stack *b);
t_stack	*ft_longest_subseq(t_stack *stack);
void	ft_push_unwanted(t_stack *a, t_stack *b, t_stack *lis);
void	ft_insert_back(t_stack *a, t_stack *b);
int		ft_get_place_insert(t_stack *stack, int value);
void	ft_operation(t_stack *main, t_stack *other, int ope);
void	ft_exec_swap(t_stack *a, t_stack *b, int stack);
void	ft_exec_push(t_stack *a, t_stack *b, char *msg);

void	ft_display_stack(t_stack stack);
int		ft_stack_sorted(t_stack *stack);
int		ft_kinda_sorted(t_stack *stack);
void	ft_put_ontop(t_stack *stack, int value);

#endif