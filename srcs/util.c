/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 22:27:43 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/08 15:50:54 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** The parameter a_or_b (short form l) is 0 if the stack being focused on is
** stack a and 1 if it is stack b
*/

static int		insertion(t_stack **s, t_list *c, int j, int l)
{
	t_list *tmp;

	tmp = (*s)->stack;
	if ((CUR(c) > CUR((*s)->stack) && !l) || (CUR(c) < CUR((*s)->stack) && l))
		while (c && tmp && CUR(c) > CUR(tmp) && ++j < (*s)->size)
			tmp = tmp->next;
	else if ((CUR(c) < CUR((*s)->stack) && !l)
			|| (CUR(c) > CUR((*s)->stack) && l))
	{
		while (c && tmp && CUR(c) < CUR(tmp) && ++j < (*s)->size)
		{
			tmp = tmp->next;
			if (c && tmp && CUR(tmp) == (*s)->min && CUR(c) < (*s)->max
					&& ++j < (*s)->size)
			{
				tmp = tmp->next;
				while (c && tmp && CUR(c) > CUR(tmp) && ++j < (*s)->size)
					tmp = tmp->next;
				return (j);
			}
		}
	}
	return (j);
}

static int		get_index_b(t_stack **a, t_stack **b, int i)
{
	int		j;
	t_list	*curr;

	j = 0;
	curr = (*a)->stack;
	while (++j < i && curr)
		curr = curr->next;
	if (CUR(curr) > CUR((*b)->stack) && CUR(curr) < CUR((*b)->end))
		return (0);
	if (CUR(curr) > (*b)->max || CUR(curr) < (*b)->min)
	{
		if ((CUR((*b)->end) == (*b)->min && CUR(curr) > (*b)->max)
				|| (CUR((*b)->stack) == (*b)->max && CUR(curr) < (*b)->min))
			return (0);
		j = 0;
		curr = (*b)->stack;
		while (curr && CUR(curr) > (*b)->min && ++j < (*b)->size)
			curr = curr->next;
		return (j);
	}
	j = insertion(b, curr, 0, 1);
	return (j);
}

static int		get_index_a(t_stack **a, t_stack **b, int i)
{
	int		j;
	t_list	*curr;

	j = -1;
	curr = (*b)->stack;
	while (++j < i && curr)
		curr = curr->next;
	if (CUR(curr) < CUR((*a)->stack) && CUR(curr) > CUR((*a)->end))
		return (0);
	if (CUR(curr) > (*a)->max || CUR(curr) < (*a)->min)
	{
		if (CUR((*a)->stack) == (*a)->min && CUR(curr) > (*a)->max)
			return (0);
		if (CUR((*a)->stack) == (*a)->max && CUR(curr) < (*a)->min)
			return (1);
		j = 0;
		curr = (*a)->stack;
		while (curr && CUR(curr) > (*a)->min && ++j < (*a)->size)
			curr = curr->next;
		return (j);
	}
	j = insertion(a, curr, 0, 0);
	return (j);
}

static void		shortest_path(t_util *util)
{
	int	x;
	int	y;

	x = MAX(util->rra, util->rrb);
	y = MAX(util->ra, util->rb);
	util->len = MIN(x, y);
	util->a_d = (x < y) ? 1 : 0;
	util->b_d = util->a_d;
	x = MIN(util->ra, util->rra);
	y = MIN(util->rb, util->rrb);
	util->len = MIN(x + y, util->len);
	if (x + y == util->len)
	{
		util->a_d = (util->rra <= util->ra) ? 1 : 0;
		util->b_d = (util->rrb <= util->rb) ? 1 : 0;
	}
}

t_util			util_init(t_stack **a, t_stack **b, int i, int a_or_b)
{
	t_util	out;

	if (!a_or_b)
	{
		out.ra = i;
		out.rra = (*a)->size - i;
		out.a_i = i;
		out.b_i = get_index_b(a, b, i);
		out.rb = out.b_i;
		out.rrb = (*b)->size - out.rb;
	}
	else
	{
		out.rb = i;
		out.rrb = (*b)->size - i;
		out.b_i = i;
		out.a_i = get_index_a(a, b, i);
		out.ra = out.a_i;
		out.rra = (*a)->size - out.ra;
	}
	shortest_path(&out);
	return (out);
}
