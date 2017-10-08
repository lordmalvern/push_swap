/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:51:52 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/05 01:45:56 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_median(t_stack **a, int start, int size)
{
	int	med;
	int i;
	int j;
	int *arr;

	i = start;
	arr = ft_memalloc(size * sizeof(int));
	list_to_arr(a, &arr);
	while (++i < size)
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			med = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = med;
			j--;
		}
	}
	med = arr[(size - start) / 2];
	free(arr);
	return (med);
}
