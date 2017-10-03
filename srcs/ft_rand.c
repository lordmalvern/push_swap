/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:40:37 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/28 14:43:40 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void twist(uint32_t *mer_t)
{
	uint32_t i;
	uint32_t x;
	uint32_t a;

	i = -1;
	while (++i < DEG)
	{
		x = (mer_t[i] & M_U) + (mer_t[(i + 1) % DEG] & M_L);
		a = x >> 1;
		if (x & 0x1)
			a ^= TST;
		mer_t[i] = mer_t[(i + MID) % DEG] ^ a;
	}
}

static uint32_t	extract(uint32_t *mer_t, uint16_t *index)
{
	uint32_t out;
	int i;

	i = *index;
	if (*index >= DEG)
	{
		twist(mer_t);
		*index = 0;
		i = *index;
	}
	out = mer_t[i];
	*index = i + 1;
	out ^= (mer_t[i] >> U);
	out ^= (out << SFT) & B_M;
	out ^= (out << BIT) & C_M;
	out ^= (out >> TEM);
	return (out);
}

uint32_t		ft_rand(int seed)
{
	static uint32_t mer_t[DEG];
	static uint16_t index;
	int i;

	if (index == 0)
	{
		mer_t[0] = seed;
		i = 0;
		while (++i < DEG)
			mer_t[i] = (F * (mer_t[i - 1] ^ (mer_t[i - 1] >> 30)) + i);
		index = DEG;
	}
	return (extract(mer_t, &index));
}
