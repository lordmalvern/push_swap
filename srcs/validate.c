/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 23:47:34 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/08 21:49:13 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			validate(t_list *a, t_list *b)
{
	t_list	*curr;
	int		prev;

	if (a->content == NULL || b != NULL)
		return (0);
	curr = a;
	prev = *((int *)curr->content);
	curr = curr->next;
	while (curr != NULL && prev < *((int *)curr->content))
	{
		prev = *((int *)curr->content);
		curr = curr->next;
	}
	if (curr != NULL)
		return (0);
	return (1);
}

int			chk_dup(t_list *stack, int n)
{
	t_list	*curr;

	curr = stack;
	if (stack == NULL || stack->content == NULL)
		return (1);
	while (curr != NULL && n != *((int *)curr->content))
		curr = curr->next;
	if (curr != NULL)
		return (0);
	return (1);
}
