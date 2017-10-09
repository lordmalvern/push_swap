/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:33:47 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/09 11:06:51 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"
# define CUR(a) *((int *)(a)->content)
# define NXT(a) *((int *)(a)->next->content)

void	parse_cmd(char *cmd, t_stack **a, t_stack **b, int debug);
int		validate(t_list *a, t_list *b);
int		chk_dup(t_stack *stack, int n);
int		parse_args(t_stack **a, char **argv, int debug, int i);
void	clean_stacks(t_stack **a, t_stack **b, int i);
void	del(void *content, size_t size);
#endif
