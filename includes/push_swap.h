/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:47:55 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/08 01:42:42 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"
# include <limits.h>
# define NUL(a) ((a) != NULL && (a)->next != NULL)
# define GT(a) (NUL(a) && *((int *)(a)->content) > *((int *)(a)->next->content))
# define LT(a) (NUL(a) && *((int *)(a)->content) < *((int *)(a)->next->content))
# define BOTH(a, b) (GT(a) && LT(b))
# define BALT(a, b) (GT(a) && GT(b))
# define ABS(a) (a < 0) ? a * -1 : a
# define NNXT(a) NXT((a)->next)
# define DCBA(a) CUR(a) > NXT(a) && NNXT(a) > NNXT(a->next)

typedef struct	s_util
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		a_i;
	int		b_i;
	int		len;
	int		a_d;
	int		b_d;
}				t_util;

void			print_cmd(char *cmd, t_stack **a, t_stack **b, int iter);
void			sort(t_stack **a, t_stack **b, int size);
int				get_median(t_stack **a, int start, int size);
void			alt_sort(t_stack **a, t_stack **b);
void			list_to_arr(t_stack **a, int **b);
int				rev_validate(t_stack *a);
t_util			util_init(t_stack **a, t_stack **b, int i, int a_or_b);
void			alt_rotate(t_stack **a, t_stack **b, t_util *util);
#endif
