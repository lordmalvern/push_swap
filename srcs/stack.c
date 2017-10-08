/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:46:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/06 11:32:30 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	push(t_stack **stack, void *elem, size_t size)
{
	static t_list *to_add;

	if ((*stack)->stack == NULL)
	{
		(*stack)->stack = ft_lstnew(elem, size);
		(*stack)->end = (*stack)->stack;
	}
	else
	{
		to_add = ft_lstnew(elem, size);
		ft_lstadd(&((*stack)->stack), to_add);
	}
}

t_list	*pop(t_stack **stack)
{
	t_list	*out;
	t_list	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = (*stack)->stack;
	(*stack)->stack = temp->next;
	out = ft_lstnew(temp->content, temp->content_size);
	free(temp->content);
	free(temp);
	return (out);
}

/*
** void bubble_up(t_list **stack)
**
** bubble_up swaps the first two elements at the top of the stack. Does nothing
** if stack contains one or no elements.
*/

void	bubble_up(t_stack **stack)
{
	void	*c;
	size_t	s;

	if ((*stack)->stack != NULL && (*stack)->stack->next != NULL)
	{
		s = (*stack)->stack->content_size;
		c = ft_memalloc(s);
		ft_memcpy(c, (*stack)->stack->next->content, s);
		ft_memcpy((*stack)->stack->next->content, (*stack)->stack->content, s);
		ft_memcpy((*stack)->stack->content, c, s);
		free(c);
	}
}

/*
** void swap(t_list **a, t_list **b)
**
** swap takes the first element at the top of a and puts it on the top of b.
** Does nothing if a is empty.
*/

void	swap(t_stack **a, t_stack **b)
{
	t_list *temp;

	if (*a != NULL)
	{
		temp = pop(a);
		(*a)->size -= 1;
		push(b, temp->content, temp->content_size);
		free(temp->content);
		free(temp);
		(*b)->size += 1;
	}
}

void	rotate(t_stack **stack)
{
	t_list *end;
	if ((*stack)->stack && (*stack)->stack->next)
	{
		end = pop(stack);
		end->next = NULL;
		(*stack)->end->next = end;
		(*stack)->end = (*stack)->end->next;
	}
}
