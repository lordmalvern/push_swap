/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:47:30 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/28 21:08:38 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	roulette(t_gene *pool)
{
	int i;
	int sum;
	int spin;

	i = -1;
	sum = 0;
	while (++i < P_SIZE)
		sum += pool[i].fitness;
	spin = (ft_rand(sum) % sum) + 1;
	i = -1;
	while (++i < P_SIZE)
	{
		spin -= pool[i].fitness;
		if (spin <= 0)
			return (i);
	}
	return (P_SIZE - 1);
}
