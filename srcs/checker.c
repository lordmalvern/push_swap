/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:32:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/10/09 11:08:02 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	parse(t_stack **a, t_stack **b, int debug)
{
	char	*cmd;

	while (get_next_line(0, &cmd))
	{
		parse_cmd(cmd, a, b, debug);
		ft_strdel(&cmd);
	}
	if (validate((*a)->stack, (*b)->stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		debug;

	i = -1;
	a = ft_memalloc(sizeof(t_stack));
	b = ft_memalloc(sizeof(t_stack));
	a->stack = NULL;
	b->stack = NULL;
	debug = 0;
	if (argc > 1)
	{
		if (ft_strequ(argv[1], "-v"))
			debug = 1;
		i = parse_args(&a, argv, debug, argc);
		if (i != -1)
			parse(&a, &b, debug);
	}
	clean_stacks(&a, &b, i);
}
