/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:02:13 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/06 15:24:39 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/ft_printf.h"

typedef struct	s_stack
{
	t_list	*stack;
	t_list	*end;
	int		size;
	int		min;
	int		max;
}				t_stack;

void	push(t_stack **stack, void *elem, size_t size);
t_list	*pop(t_stack **stack);
void	bubble_up(t_stack **stack);
void	swap(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

#endif
