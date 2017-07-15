/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:02:13 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/14 21:04:55 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/ft_printf.h"

void	push(t_list **stack, void *elem, size_t size);
t_list	*pop(t_list **stack);
void	bubble_up(t_list **stack);
void	swap(t_list **a, t_list **b);
void	rotate(t_list **stack);

#endif
