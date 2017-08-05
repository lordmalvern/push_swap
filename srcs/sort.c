/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 13:11:06 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/04 22:49:58 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rev_validate(t_list *a)
{
	t_list	*curr;
	int		prev;

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
/*
static void	sort_swap(t_list **a, t_list **b)
{
	int ca;
	int cb;
	int na;
	int nb;

	ca = *((int *)(*a)->content);
	cb = *((int *)(*b)->content);
	na = *((int *)(*a)->next->content);
	nb = *((int *)(*b)->next->content);
	if (ca >= na && cb <= nb)
		print_cmd("ss", a, b);
	else if (ca >= na)
		print_cmd("sa", a, b);
	else if (cb <= nb)
		print_cmd("sb", a, b);
}

static void	sort_rotate(t_list **a, t_list **b)
{
	int a_val;
	int b_val;

	a_val = validate(*a, NULL);
	b_val = rev_validate(*b);
	if (!a_val && !b_val)
		print_cmd("rr", a, b);
	else if (!a_val)
		print_cmd("ra", a, b);
	else if (!b_val)
		print_cmd("rb", a, b);
}

static void	merge(t_list **a, t_list **b)
{
	int va;
	int vb;

	while (*b != NULL)
	{
		va = *((int *)(*a)->content);
		vb = *((int *)(*b)->content);
		print_cmd("pa", a, b);
		if (vb > va)
			print_cmd("ra", a, b);
	}
}
*/

static void	swap_sort(t_list **a, t_list **b)
{
	int r;
	int i;

	r = 2;
	i = 0;
	while (!validate(*a, NULL) || !rev_validate(*b))
	{
		if (BOTH(*a, *b))
			print_cmd("ss", a, b);
		else if (GT(*a))
			print_cmd("sa", a, b);
		else if (LT(*b))
			print_cmd("sb", a, b);
		i = r;
		while (i-- > 0)
		{
			if (!validate(*a, NULL) && !rev_validate(*b))
				print_cmd("rr", a, b);
			else if (!validate(*a, NULL))
				print_cmd("ra", a, b);
			else if (!rev_validate(*b))
				print_cmd("rb", a, b);
		}
		r++;
	}
}

void		sort(t_list **a, t_list **b, int size)
{
	int m;
	int i;

	m = size / 2;
	i = 0;
	if (GT(*a) && size <= 3)
	{
		print_cmd("sa", a, b);
		print_cmd("rra", a, b);
	}
	if (!validate(*a, *b))
	{
		while (i++ < m)
			print_cmd("pb", a, b);
		swap_sort(a, b);
		while (*b != NULL)
		{
			print_cmd("pa", a, b);
			if (!validate(*a, NULL))
			{
				print_cmd("rra", a, b);
				if (!validate(*a, NULL))
					swap_sort(a, b);
			}
		}
	}
}
