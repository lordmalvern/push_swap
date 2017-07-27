/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:30:17 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/26 22:28:47 by bpuschel         ###   ########.fr       */
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

void		parse_cmd(char *cmd, t_list **a, t_list **b, int debug)
{
	if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "ss"))
		bubble_up(a);
	else if (ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss"))
		bubble_up(b);
	else if (ft_strequ(cmd, "pa"))
		swap(b, a);
	else if (ft_strequ(cmd, "pb"))
		swap(a, b);
	else if (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rr"))
		rotate(a);
	else if (ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr"))
		rotate(b);
	else if (ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrr"))
		rrotate(a);
	else if (ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr"))
		rrotate(b);
	else
		ft_printf("Error\n");
	if (debug)
		debug_print(*a, *b);
}
