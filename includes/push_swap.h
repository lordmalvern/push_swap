/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:47:55 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/04 15:40:44 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "checker.h"
# define NUL(a) ((a) != NULL && (a)->next != NULL)
# define GT(a) (NUL(a) && *((int *)(a)->content) > *((int *)(a)->next->content))
# define LT(a) (NUL(a) && *((int *)(a)->content) < *((int *)(a)->next->content))
# define BOTH(a, b) (GT(a) && LT(b))
# define CUR(a) *((int *)(a)->content)
# define NXT(a) *((int *)(a)->next->content)

void	print_cmd(char *cmd, t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, int size);
int		get_median(t_list **a, int start, int size);
void	alt_sort(t_list **a, t_list **b, int size);
void	merge_sort(int *a, int *b, int size);
int		ft_bsearch(int *arr, int key, int size);
void	list_to_arr(t_list **a, int **b);
#endif
