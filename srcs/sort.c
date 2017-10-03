/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 13:11:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/23 01:45:14 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rev_validate(t_list *a)
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

static void	rotate_stacks(t_list **a, t_list **b, int i)
{
	if (i % 2 == 0)
	{
		if (!validate(*a, NULL) && !rev_validate(*b))
			print_cmd("rr", a, b, 1);
		else if (!validate(*a, NULL))
			print_cmd("ra", a, b, 1);
		else if (!rev_validate(*b))
			print_cmd("rb", a, b, 1);
	}
	else
	{
		if (!validate(*a, NULL) && !rev_validate(*b))
			print_cmd("rrr", a, b, 1);
		else if (!validate(*a, NULL))
			print_cmd("rra", a, b, 1);
		else if (!rev_validate(*b))
			print_cmd("rrb", a, b, 1);
	}
}

static void	swap_sort(t_list **a, t_list **b, int size)
{
	int		r;
	int		start;

	r = (size > 5) ? 2 : 1;
	start = 0;
	while (!validate(*a, NULL) || !rev_validate(*b))
	{
		if (BOTH(*a, *b))
			print_cmd("ss", a, b, 1);
		else if (GT(*a))
			print_cmd("sa", a, b, 1);
		else if (LT(*b))
			print_cmd("sb", a, b, 1);
		rotate_stacks(a, b, r);
		start++;
		start = (start >= size) ? 0 : start;
		r = (start == 0) ? r + 1 : r;
	}
}

static void	merge(t_list **a, t_list **b, int size)
{
	while (*b != NULL)
	{
		print_cmd("pa", a, b, 1);
		if (!validate(*a, NULL) && *b != NULL)
			print_cmd("ra", a, b, 1);
	}
	if (!validate(*a, NULL))
		sort(a, b, size);
}

void		sort(t_list **a, t_list **b, int size)
{
	int m;
	int i;

	m = get_median(a, 0, size);
	i = 0;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (size < 4 && !validate(*a, *b))
		swap_sort(a, b, size / 2);
	if (!validate(*a, *b))
	{
		while (i++ < size)
		{
			if (CUR(*a) <= m)
				print_cmd("pb", a, b, 1);
			else
				print_cmd("ra", a, b, 1);
		}
		swap_sort(a, b, size);
		merge(a, b, size);
	}
}
