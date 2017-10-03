/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:54:02 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/02 19:08:11 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		print_fittest(t_gene fittest, int *arr, int size, int limit)
{
	int i;
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	i = size;
	while (--i >= 0)
		push(&a, &arr[i], sizeof(int));
	i = -1;
	while (++i < limit && !validate(a, b))
		ft_printf("%s\n", fittest.cmds[i]);
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
}

static void		generate_pool(t_gene **pool, int limit, char **cmd)
{
	int				i;
	int				j;
	unsigned int	rand;
	unsigned int	b_count;

	i = -1;
	b_count = 0;
	while (++i < P_SIZE)
	{
		j = -1;
		while (++j < limit)
		{
			rand = (b_count < 2) ? ft_rand(limit) % 4 : ft_rand(limit) % 11;
			b_count = (ft_strcmp(cmd[rand], "pb") == 0) ? b_count + 1 : b_count;
			pool[0][i].cmds[j] = ft_strdup(cmd[rand]);
		}
	}
}

unsigned int	get_fitness(int *arr, char **cmds, int size, int limit)
{
	int				i;
	t_list			*a;
	t_list			*b;
	t_list			*curr;
	unsigned int	score;

	a = NULL;
	b = NULL;
	i = size;
	while (--i >= 0)
		push(&a, &arr[i], sizeof(int));
	i = -1;
	while (++i < limit && !validate(a, b))
		parse_cmd(cmds[i], &a, &b, 0);
	score = 0;
	curr = a;
	if (i < limit || validate(a, b))
		score = size;
	else
		while (!b && LT(curr) && ++score)
			curr = curr->next;
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
	return (score);
}

static t_gene	get_fittest(int *arr, t_gene *pool, int size, int limit)
{
	int				i;
	unsigned int	max;
	unsigned int	curr_fit;
	unsigned int	i_max;

	i = -1;
	max = 0;
	i_max = 0;
	while (++i < limit)
	{
		if (!pool[i].fitness)
			curr_fit = get_fitness(arr, pool[i].cmds, size, limit);
		else
			curr_fit = pool[i].fitness;
		i_max = (curr_fit > max) ? i : i_max;
		max = MAX(curr_fit, max);
	}
	return (pool[i_max]);
}

void			evolve(int *arr, char **cmd, int size)
{
	t_gene			*pool;
	unsigned int	limit;
	t_gene			fittest;
	int				i;

	limit = MAX((size * ft_log(size)) / ft_log(2), 7 * size);
	pool = (t_gene *)ft_memalloc(P_SIZE * sizeof(t_gene));
	i = -1;
	while (++i < P_SIZE)
		pool[i].cmds = (char **)ft_memalloc(limit * sizeof(char *));
	generate_pool(&pool, limit, cmd);
	i = -1;
	while (++i < P_SIZE)
		pool[i].fitness = get_fitness(arr, pool[i].cmds, size, limit);
	fittest = get_fittest(arr, pool, size, limit);
	while (fittest.fitness < size)
	{
		pool = breed(&pool, arr, size, limit);
		mutate(&pool, cmd, limit);
		fittest = get_fittest(arr, pool, size, limit);
		ft_printf("Max fitness: %d\n", fittest.fitness);
	}
	print_fittest(fittest, arr, size, limit);
	clean_pool(&pool, limit);
}
