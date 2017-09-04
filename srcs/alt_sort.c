/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/04 16:06:28 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_bsearch(int *arr, int key, int size)
{
	int left;
	int right;
	int mid;

	left = 0;
	right = size - 1;
	if (arr[left] > arr[right])
		return (-1);
	while (left != right)
	{	
		if (arr[left] == key)
			return (left);
		if (arr[right] == key)
			return (right);
		mid = (left + right) / 2;
		if (arr[mid] == key)
			return (mid);
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	list_to_arr(t_list **a, int **b)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = *a;
	while (curr)
	{
		b[0][i] = CUR(curr);
		curr = curr->next;
		i++;
	}
}

static void	stack_sort(t_list **a, t_list **b, int *sorted, int size)
{
	int i;

	while (!validate(*a, *b))
	{
		i = ft_bsearch(sorted, CUR(*a), size);
		if (i > 0 && NXT(*a) <= sorted[i - 1])
			print_cmd("sa", a, b);
		else if (i < size - 1 && NXT(*a) != sorted[i + 1])
		{
			print_cmd("pb", a, b);
			while (CUR(*a) != sorted[i + 1])
				print_cmd("ra", a, b);
			print_cmd("pa", a, b);
		}
		print_cmd("rra", a, b);
	}
}

void	merge_sort(int *a, int *b, int size)
{
	int w;
	int i;
	int j;
	int k;
	int e;

	w = 1;
	while (w < size)
	{
		i = 0;
		while (i < size)
		{
			j = MIN(i + w, size);
			e = MIN(i + (2 * w), size);
			k = i - 1;
			while (++k < e)
				b[k] = (i < j && (j >= e || (a[i] <= a[j]))) ? a[i++] : a[j++];
			i = (e == size) ? i : e - (2 * w);
			i += 2 * w;
		}
		ft_memcpy(a, b, size * sizeof(int));
		w *= 2;
	}
}

void	alt_sort(t_list **a, t_list **b, int size)
{
	int		*sorted;
	int		*helper;

	sorted = ft_memalloc(size * sizeof(int));
	helper = ft_memalloc(size * sizeof(int));
	list_to_arr(a, &sorted);
	merge_sort(sorted, helper, size);
	stack_sort(a, b, sorted, size);
	free(sorted);
	free(helper);
}
