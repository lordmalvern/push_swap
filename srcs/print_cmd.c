/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:34:36 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/05 01:28:17 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_cmd(char *cmd, t_stack **a, t_stack **b, int iter)
{
	int i;

	i = -1;
	while (++i < iter)
	{
		parse_cmd(cmd, a, b, 0);
		ft_printf("%s\n", cmd);
	}
}
