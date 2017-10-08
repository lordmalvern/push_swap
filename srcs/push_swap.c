/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 22:54:12 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/07 14:29:45 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_memalloc(sizeof(t_stack));
	a->stack = NULL;
	a->size = argc - 1;
	b = ft_memalloc(sizeof(t_stack));
	b->stack = NULL;
	b->size = 0;
	if (argc == 1)
		return (0);
	parse_args(&a, argv, 0, argc);
	if (argc - 1 <= 5)
		sort(&a, &b, argc - 1);
	else
		alt_sort(&a, &b);
	ft_lstdel(&(a->stack), del);
	ft_lstdel(&(b->stack), del);
	free(a);
	free(b);
	exit(0);
}
