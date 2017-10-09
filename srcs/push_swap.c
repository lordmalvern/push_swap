/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 22:54:12 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/09 11:06:29 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	a = (t_stack *)ft_memalloc(sizeof(t_stack));
	a->stack = NULL;
	a->size = argc - 1;
	b = (t_stack *)ft_memalloc(sizeof(t_stack));
	b->stack = NULL;
	b->size = 0;
	if (argc > 1)
	{
		i = parse_args(&a, argv, 0, argc);
		if (i != -1 && argc - 1 <= 5 && !validate(a->stack, b->stack))
			sort(&a, &b, argc - 1);
		else if (i != -1 && !validate(a->stack, b->stack))
			alt_sort(&a, &b);
	}
	clean_stacks(&a, &b, i);
}
