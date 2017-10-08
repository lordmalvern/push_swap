/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/08 01:24:17 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_order(t_stack *a)
{
	t_list *curr;

	curr = a->stack;
	if (CUR(curr) == a->max)
	{
		curr = curr->next;
		while (curr->next && CUR(curr) < NXT(curr))
			curr = curr->next;
		if (curr->next)
			return (0);
	}
	else
	{
		while (curr->next)
		{
			if (CUR(curr) > NXT(curr) && NXT(curr) != a->max)
				return (0);
			curr = curr->next;
		}
	}
	return (1);
}

static void find_minimax(t_list *a, int *min, int *max)
{
	t_list *curr;

	curr = a;
	*min = INT_MAX;
	*max = INT_MIN;
	while (curr)
	{
		if (CUR(curr) < *min)
			*min = CUR(curr);
		if (CUR(curr) > *max)
			*max = CUR(curr);
		curr = curr->next;
	}
}

static void	stack_sort_b(t_stack **a, t_stack **b)
{
	int		i;
	t_util	util;
	t_util	tmp;

	while ((*b)->size != 0)
	{
		i = 0;
		util = util_init(a, b, i, 1);
		while (++i < (*b)->size)
		{
			tmp = util_init(a, b, i, 1);
			if (tmp.len < util.len)
				util = tmp;
		}
		alt_rotate(a, b, &util);
		print_cmd("pa", a, b, 1);
		find_minimax((*a)->stack, &((*a)->min), &((*a)->max));
		find_minimax((*b)->stack, &((*b)->min), &((*b)->max));
	}
}

static void	stack_sort(t_stack **a, t_stack **b)
{
	int		i;
	t_util	util;
	t_util	tmp;

	while (!check_order(*a))
	{
		i = 0;
		util = util_init(a, b, i, 0);
		while (++i < (*a)->size)
		{
			tmp = util_init(a, b, i, 0);
			if (tmp.len < util.len)
				util = tmp;
		}
		alt_rotate(a, b, &util);
		if (!check_order(*a))
			print_cmd("pb", a, b, 1);
		find_minimax((*a)->stack, &((*a)->min), &((*a)->max));
		find_minimax((*b)->stack, &((*b)->min), &((*b)->max));
	}
	stack_sort_b(a, b);
}

void		alt_sort(t_stack **a, t_stack **b)
{
	int i;
	t_list *curr;

	if (CUR((*a)->stack) > NXT((*a)->stack) 
			&& NNXT((*a)->stack) > NNXT((*a)->stack->next))
	{
		print_cmd("pb", a, b, 2);
		print_cmd("ss", a, b, 1);
	}
	else if (CUR((*a)->stack) > NXT((*a)->stack))
		print_cmd("sa", a, b, 1);
	while (((*b)->size == 0 || CUR((*a)->stack) > CUR((*b)->stack)) 
			&& (*a)->size > 2)
		print_cmd("pb", a, b, 1);
	find_minimax((*a)->stack, &((*a)->min), &((*a)->max));
	find_minimax((*b)->stack, &((*b)->min), &((*b)->max));
	stack_sort(a, b);
	i = 0;
	curr = (*a)->stack;
	if (CUR(curr) != (*a)->min)
		while (curr && CUR(curr) != (*a)->min && ++i < (*a)->size)
			curr = curr->next;
	while (i >= (*a)->size / 2 && CUR((*a)->stack) != (*a)->min)
		print_cmd("rra", a, b, 1);
	while (i > 0 && i < (*a)->size / 2 && CUR((*a)->stack) != (*a)->min)
		print_cmd("ra", a, b, 1);
}
