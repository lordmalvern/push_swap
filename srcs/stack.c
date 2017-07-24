/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:46:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/23 17:55:13 by bpuschel         ###   ########.fr       */
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

/*
** void bubble_up(t_list **stack)
**
** bubble_up swaps the first two elements at the top of the stack. Does nothing
** if stack contains one or no elements.
*/

void	bubble_up(t_list **stack)
{
	t_list	*temp;
	int		size;

	temp = *stack;
	size = 0;
	while (temp != NULL || size++)
		temp = temp->next;
	if (size > 1)
	{
		temp = *stack;
		temp->next = (*stack)->next->next;
		*stack = (*stack)->next;
		(*stack)->next = temp;
		free(temp);
	}
}

/*
** void swap(t_list **a, t_list **b)
**
** swap takes the first element at the top of a and puts it on the top of b.
** Does nothing if a is empty.
*/

void	swap(t_list **a, t_list **b)
{
	t_list *temp;

	if (*a != NULL)
	{
		temp = pop(a);
		push(b, temp->content, temp->content_size);
		free(temp);
	}
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
