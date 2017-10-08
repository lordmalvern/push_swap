/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 00:27:15 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/08 00:49:36 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			alt_rotate(t_stack **a, t_stack **b, t_util *util)
{
	if (!util->a_d && !util->b_d && util->ra > 0 && util->rb > 0)
		while (util->ra && util->rb && --util->ra >= 0 && --util->rb >= 0)
			print_cmd("rr", a, b, 1);
	if (!util->a_d)
		while (--util->ra >= 0)
			print_cmd("ra", a, b, 1);
	if (!util->b_d)
		while (--util->rb >= 0)
			print_cmd("rb", a, b, 1);
	if (util->a_d && util->b_d && util->rra > 0 && util->rrb > 0)
		while (util->rra && util->rrb && --util->rra >= 0 && --util->rrb >= 0)
			print_cmd("rrr", a, b, 1);
	if (util->a_d)
		while (util->a_d && --util->rra >= 0)
			print_cmd("rra", a, b, 1);
	if (util->b_d)
		while (util->b_d && --util->rrb >= 0)
			print_cmd("rrb", a, b, 1);
}
