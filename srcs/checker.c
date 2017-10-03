/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:32:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/26 15:41:21 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	parse(t_list **a, t_list **b, int debug)
{
	char	*cmd;

	while (get_next_line(0, &cmd))
		parse_cmd(cmd, a, b, debug);
	if (validate(*a, *b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int			main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		debug;

	a = NULL;
	b = NULL;
	debug = 0;
	i = argc;
	if (argc == 1)
		return (0);
	if (ft_strequ(argv[1], "-v"))
		debug = 1;
	parse_args(&a, argv, debug, i);
	parse(&a, &b, debug);
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
	return (0);
}
