/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 13:11:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/25 12:49:32 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rev_validate(t_list *a)
{
	t_list	*curr;
	int		prev;

	if (a == NULL)
		return (1);
	if (a->content == NULL)
		return (0);
	curr = a;
	prev = *((int *)curr->content);
	curr = curr->next;
	while (curr != NULL && prev > *((int *)curr->content))
	{
		prev = *((int *)curr->content);
		curr = curr->next;
	}
	if (curr != NULL)
		return (0);
	return (1);
}

static void rotate_stacks(t_list **a, t_list **b, int i)
{
	while (i > 0)
	{
		if (!validate(*a, NULL) && !rev_validate(*b))
			print_cmd("rr", a, b);
		else if (!validate(*a, NULL))
			print_cmd("ra", a, b);
		else if (!rev_validate(*b))
			print_cmd("rb", a, b);
		i--;
	}
}

static void	swap_sort(t_list **a, t_list **b)
{
	int r;
	int start;
	int size;
	t_list *curr;

	r = 1;
	start = 0;
	size = 0;
	curr = *a;
	while (curr != NULL && ++size)
		curr = curr->next;
	while (!validate(*a, NULL) || !rev_validate(*b))
	{
		if (BOTH(*a, *b))
			print_cmd("ss", a, b);
		else if (GT(*a))
			print_cmd("sa", a, b);
		else if (LT(*b))
			print_cmd("sb", a, b);
		rotate_stacks(a, b, r);
		start += r;
		if (start >= size - 2 && ++r)
			start = 0;
	}
}

static void	merge(t_list **a, t_list **b)
{
	while (*b != NULL)
	{
		print_cmd("pa", a, b);
		if (!validate(*a, NULL))
		{
			if (*b != NULL)
				print_cmd("ra", a, b);
			if (!validate(*a, NULL))
				swap_sort(a, b);
		}
	}
}

void		sort(t_list **a, t_list **b, int size)
{
	int m;
	int i;

	m = size / 2;
	i = 0;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (GT(*a) && size <= 3 && !validate(*a, *b))
	{
		print_cmd("sa", a, b);
		print_cmd("rra", a, b);
	}
	if (!validate(*a, *b))
	{
		while (i++ < m)
			print_cmd("pb", a, b);
		swap_sort(a, b);
		merge(a, b);
	}
}
