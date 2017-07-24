/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:30:17 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/23 17:23:18 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	parse_cmd(char *cmd, t_list **a, t_list **b)
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
	else
		ft_printf("Error\n");
}
