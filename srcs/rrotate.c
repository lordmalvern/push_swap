/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:28:25 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/27 22:20:34 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	rrotate(t_list **stack)
{
	t_list *curr;
	
	curr = *stack;
	if (curr)
	{
		while (curr->next && curr->next->next)
			curr = curr->next;
		if (curr->next)
		{
			push(stack, curr->next->content, curr->next->content_size);
			free(curr->next);
			curr->next = NULL;
		}
	}
}
