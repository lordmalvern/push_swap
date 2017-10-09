/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:28:25 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/08 18:49:38 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	rrotate(t_stack **stack)
{
	t_list *curr;

	curr = (*stack)->stack;
	if ((*stack)->stack && (*stack)->end)
	{
		while (curr && curr->next != (*stack)->end)
			curr = curr->next;
		if ((*stack)->end && curr)
		{
			push(stack, curr->next->content, curr->next->content_size);
			if (curr->next)
				free(curr->next->content);
			free(curr->next);
			curr->next = NULL;
			(*stack)->end = curr;
		}
	}
}
