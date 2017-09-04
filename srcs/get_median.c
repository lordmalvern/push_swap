/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:51:52 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/04 15:40:51 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*int	get_ninther(t_list **a, int start, int size)
{
	int s;
	int mid;
	int e;

	s = get_median(a, start, size / 3);
	mid = get_median(a, (size / 3) - 1, 2 * (size / 3));
	e = get_median(a, (2 * (size / 3)) - 1, size);
	if ((s - mid) * (mid - e) > 0)
		return (mid);
	else if ((s - mid) * (s - e) > 0)
		return (e);
	else
		return (s);
}*/
int	get_median(t_list **a, int start, int size)
{
/*	int		mid;
	int		s;
	t_list	*curr;
	int		e;
	int		i;

	curr = *a;
	i = start;
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
		return (s);*/
	int	med;
	int	*sorted;
	int	*helper;
	
	sorted = ft_memalloc(size * sizeof(int));
	helper = ft_memalloc(size * sizeof(int));
	list_to_arr(a, &sorted);
	merge_sort(sorted, helper, size);
	med = sorted[((size - 1) - start) / 2];
	free(sorted);
	free(helper);
	return (med);
}
