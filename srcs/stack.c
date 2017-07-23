/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:46:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/22 17:48:52 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	push(t_list **stack, void *elem, size_t size)
{
	t_list *to_add;

	to_add = ft_lstnew(elem, size);
	ft_lstadd(stack, to_add);
	free(to_add);
}

t_list	*pop(t_list **stack)
{
	t_list *out;
	t_list *temp;

	temp = *stack;
	*stack = temp->next;
	out = ft_lstnew(temp->content, temp->content_size);
	free(temp);
	return (out);
}

void	bubble_up(t_list **stack)
{
	t_list *temp;

	temp = *stack;
	temp->next = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	free(temp);
}

void	swap(t_list **a, t_list **b)
{
	t_list *temp;

	temp = pop(a);
	push(b, temp->content, temp->content_size);
	free(temp);
}

void	rotate(t_list **stack)
{
	t_list *end;
	t_list *curr;

	end = pop(stack);
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = end;
}
