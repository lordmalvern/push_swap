/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breed_and_mutate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:25:39 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/02 19:08:24 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		clean_pool(t_gene **pool, int limit)
{
	int i;
	int j;

	i = -1;
	while (++i < P_SIZE)
	{
		j = -1;
		while (++j < limit)
			free(pool[0][i].cmds[j]);
	}
	free(pool[0]);
}

static t_gene	crossover(int *arr, t_gene *pool, int size, int limit)
{
	int		i;
	t_gene	g;
	t_gene	m;
	t_gene	f;
	
	m = pool[roulette(pool)];
	f = pool[roulette(pool)];
	g.cmds = (char **)ft_memalloc(limit * sizeof(char *));
	g.fitness = 0;
	i = -1;
	while (++i < limit)
	{
		if ((MAX(m.fitness, f.fitness) == m.fitness && g.fitness < m.fitness)
				|| (MIN(m.fitness, f.fitness) == m.fitness 
					&& g.fitness > f.fitness))
			g.cmds[i] = ft_strdup(m.cmds[i]);
		else
			g.cmds[i] = ft_strdup(f.cmds[i]);
		g.fitness = get_fitness(arr, g.cmds, size, i + 1);
	}
	return (g);
}

void		mutate(t_gene **pool, char **cmd, int limit)
{
	int	i;
	int	j;

	i = -1;
	while (++i < P_SIZE)
	{
		j = -1;
		while (++j < limit)
		{
			if ((ft_rand(limit) % 1000) <= MUT_RATE)
			{
				free(pool[0][i].cmds[j]);
				pool[0][i].cmds[j] = ft_strdup(cmd[ft_rand(limit) % 11]);
			}
		}
	}
}

t_gene		*breed(t_gene **pool, int *arr, int size, unsigned int limit)
{
	t_gene	*new_pool;
	int		i;

	new_pool = (t_gene *)ft_memalloc(P_SIZE * sizeof(t_gene));
	i = -1;
	while (++i < P_SIZE)
		new_pool[i] = crossover(arr, *pool, size, limit);
	clean_pool(pool, limit);
	return (new_pool);
}
