/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:33:47 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/31 14:04:48 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"

void	parse_cmd(char *cmd, t_list **a, t_list **b, int debug);
int		validate(t_list *a, t_list *b);
int		chk_dup(t_list *stack, int n);
#endif
