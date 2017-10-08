/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:47:55 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/07 10:22:37 by bpuschel         ###   ########.fr       */
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
# define MAX_RAND 2147483648
# define ABS(a) (a < 0) ? a * -1 : a
# define P_SIZE 200
# define MUT_RATE 20
# define T_SIZE 4
# define NNXT(a) NXT((a)->next)
# define ABC(a) (CUR(a) < NXT(a) && NXT(a) < NNXT(a) && CUR(a) < NNXT(a))
# define ACB(a) (CUR(a) < NXT(a) && NXT(a) > NNXT(a) && CUR(a) < NNXT(a))
# define BAC(a) (CUR(a) > NXT(a) && NXT(a) < NNXT(a) && CUR(a) < NNXT(a))
# define BCA(a) (CUR(a) < NXT(a) && NXT(a) > NNXT(a) && CUR(a) > NNXT(a))
# define CAB(a) (CUR(a) > NXT(a) && NXT(a) < NNXT(a) && CUR(a) > NNXT(a))
# define CBA(a) (CUR(a) > NXT(a) && NXT(a) > NNXT(a) && CUR(a) > NNXT(a))

typedef enum	e_rand 
{
	DEG = 624,
	MID = 397,
	SEP = 31,
	TST = 0x9908B0DF,
	F = 1812433253,
	U = 11,
	SFT = 7,
	B_M = 0x9D2C5680,
	BIT = 15,
	C_M = 0xEFC60000,
	TEM = 18,
	M_L = (1ull << SEP) - 1,
	M_U = (1ull << SEP)
}				t_rand;

typedef struct	s_gene
{
	char				**cmds;
	int					fitness;
}				t_gene;

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
uint32_t		ft_rand(uint32_t seed);
uint32_t		rand_to(uint32_t seed, int n);
void			evolve(int *arr, char **cmd, int size);
int				roulette(t_gene *pool);
int				tournament(t_gene *pool);
t_gene			*breed(t_gene **pool, int *arr, int size, unsigned int limit);
void			mutate(t_gene **pool, char **cmd, int limit);
unsigned int	get_fitness(int *arr, char **cmds, int size, int limit);
void			clean_pool(t_gene **pool, int limit);
t_gene			create_alpha(int *arr, int size, int limit);
t_util			util_init(t_stack **a, t_stack **b, int i, int a_or_b);
void			alt_rotate(t_stack **a, t_stack **b, t_util *util);
#endif
