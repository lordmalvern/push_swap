/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:46:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/26 22:10:03 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	push(t_list **stack, void *elem, size_t size)
{
	t_list *to_add;

	if (*stack == NULL)
		*stack = ft_lstnew(elem, size);
	else
	{
		to_add = ft_lstnew(elem, size);
		ft_lstadd(stack, to_add);
	}
}

t_list	*pop(t_list **stack)
{
	t_list *out;
	t_list *temp;

	if (*stack == NULL)
		return (NULL);
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
	void	*c;
	size_t	s;

	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		s = (*stack)->content_size;
		c = ft_memalloc(s);
		ft_memcpy(c, (*stack)->next->content, s);
		ft_memcpy((*stack)->next->content, (*stack)->content, s);
		ft_memcpy((*stack)->content, c, s);
		free(c);
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
