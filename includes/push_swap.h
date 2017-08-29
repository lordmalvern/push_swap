/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:47:55 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/28 19:57:41 by bpuschel         ###   ########.fr       */
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

void	print_cmd(char *cmd, t_list **a, t_list **b);
void	sort(t_list **a, t_list **b, int size);
int		get_median(t_list **a, int size);
#endif
