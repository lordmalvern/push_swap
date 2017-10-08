/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:30:17 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/07 19:05:37 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	debug_print(t_list *a, t_list *b)
{
	if (b == NULL || a == NULL)
	{
		while (a != NULL)
		{
			ft_printf("%-14d\n", *((int *)a->content));
			a = a->next;
		}
		while (b != NULL)
		{
			ft_printf("%28d\n", *((int *)b->content));
			b = b->next;
		}
		ft_printf("---------------\n");
	}
	else
	{
		ft_printf("%-14d%14d\n", *((int *)a->content), *((int *)b->content));
		debug_print(a->next, b->next);
	}
}

static int	is_valid(char *cmd)
{
	if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss"))
		return (1);
	if (ft_strequ(cmd, "pa") || ft_strequ(cmd, "pb"))
		return (1);
	if (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr"))
		return (1);
	if (ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr"))
		return (1);
	return (0);
}

void		parse_cmd(char *cmd, t_stack **a, t_stack **b, int debug)
{
	if (is_valid(cmd))
	{
		if ((ft_strequ(cmd, "sa") || ft_strequ(cmd, "ss")) && *a)
			bubble_up(a);
		if ((ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss")) && *b)
			bubble_up(b);
		if (ft_strequ(cmd, "pa") && *b)
			swap(b, a);
		if (ft_strequ(cmd, "pb") && *a)
			swap(a, b);
		if ((ft_strequ(cmd, "ra") || ft_strequ(cmd, "rr")) && *a)
			rotate(a);
		if ((ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr")) && *b)
			rotate(b);
		if ((ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrr")) && *a)
			rrotate(a);
		if ((ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr")) && *b)
			rrotate(b);
	}
	else
		ft_printf("Error\n");
	if (debug)
		debug_print((*a)->stack, (*b)->stack);
}
