/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:28:25 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/22 17:51:59 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

void	rrotate(t_list **stack)
{
	t_list *curr;

	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	push(stack, curr->next->content, curr->next->content_size);
	free(curr->next);
	curr->next = NULL;
}
