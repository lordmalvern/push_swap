/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:30:17 by bpuschel          #+#    #+#             */
/*   Updated: 2017/08/28 21:29:50 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	debug_print(t_list *a, t_list *b)
{
	if (b == NULL)
	{
		while (a != NULL)
		{
			ft_printf("%-15d\n", *((int *)a->content));
			a = a->next;
		}
		ft_printf("---------------\n");
	}
	else if (a == NULL)
	{
		while (b != NULL)
		{
			ft_printf("%15d\n", *((int *)b->content));
			b = b->next;
		}
		ft_printf("---------------\n");
	}
	else
	{
		ft_printf("%-15d%d\n", *((int *)a->content), *((int *)b->content));
		debug_print(a->next, b->next);
	}
}

static int	is_valid(char *cmd)
{
	if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss"))
		return (1);
	if (ft_strequ(cmd, "pa"))
		return (1);
	if (ft_strequ(cmd, "pb"))
		return (1);
	if (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr"))
		return (1);
	if (ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr"))
		return (1);
	return (0);
}

void		parse_cmd(char *cmd, t_list **a, t_list **b, int debug)
{
	if (is_valid(cmd))
	{
		if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "ss"))
			bubble_up(a);
		if (ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss"))
			bubble_up(b);
		if (ft_strequ(cmd, "pa"))
			swap(b, a);
		if (ft_strequ(cmd, "pb"))
			swap(a, b);
		if (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rr"))
			rotate(a);
		if (ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr"))
			rotate(b);
		if (ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrr"))
			rrotate(a);
		if (ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr"))
			rrotate(b);
	}
	else
		ft_printf("Error\n");
	if (debug)
		debug_print(*a, *b);
}
