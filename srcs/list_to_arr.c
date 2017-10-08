/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 14:59:52 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/05 01:48:16 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_to_arr(t_stack **a, int **b)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = (*a)->stack;
	while (curr)
	{
		b[0][i] = CUR(curr);
		curr = curr->next;
		i++;
	}
}
