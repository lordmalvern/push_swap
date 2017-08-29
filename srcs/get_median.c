/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:51:52 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/28 21:28:13 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_median(t_list **a, int size)
{
	int		mid;
	int		s;
	t_list	*curr;
	int		e;
	int		i;

	curr = *a;
	i = 0;
	s = *((int *)curr->content);
	while (curr->next != NULL)
	{
		if (i == size / 2)
			mid = *((int *)curr->content);
		curr = curr->next;
		i++;
	}
	e = *((int *)curr->content);
	if ((s - mid) * (mid - e) > 0)
		return (mid);
	else if ((s - mid) * (s - e) > 0)
		return (e);
	else
		return (s);
}
