/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:47:55 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/02 19:53:05 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"
# define NUL(a) ((a) != NULL && (a)->next != NULL)
# define GT(a) (NUL(a) && *((int *)(a)->content) > *((int *)(a)->next->content))
# define LT(a) (NUL(a) && *((int *)(a)->content) < *((int *)(a)->next->content))
# define BOTH(a, b) (GT(a) && LT(b))
# define BALT(a, b) (GT(a) && GT(b))
# define END(a, x, n) (CUR(a) == x && NXT(a) == n)
# define ABS(a) (a < 0) ? a * -1 : a
# define P_SIZE 100
# define MUT_RATE 20

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

void			print_cmd(char *cmd, t_list **a, t_list **b, int iter);
void			sort(t_list **a, t_list **b, int size);
int				get_median(t_list **a, int start, int size);
void			alt_sort(t_list **a, int size);
void			list_to_arr(t_list **a, int **b);
int				rev_validate(t_list *a);
uint32_t		ft_rand(int seed);
void			evolve(int *arr, char **cmd, int size);
int				roulette(t_gene *pool);
t_gene			*breed(t_gene **pool, int *arr, int size, unsigned int limit);
void			mutate(t_gene **pool, char **cmd, int limit);
unsigned int	get_fitness(int *arr, char **cmds, int size, int limit);
void			clean_pool(t_gene **pool, int limit);
#endif
