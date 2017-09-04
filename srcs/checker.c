/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:32:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/04 14:37:44 by bpuschel         ###   ########.fr       */
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

static void	del(void *content, size_t size)
{
	ft_memdel(&content);
	size = 0;
}

static void	parse_args(t_list **a, char **argv, int debug, int i)
{
	int		n;
	int		j;
	char	**args;

	while (--i > debug)
	{
		if (strchr(argv[i], ' ') != NULL)
		{
			args = ft_strsplit(argv[i], ' ');
			j = 0;
			while (args[j] != NULL)
				j++;
			parse_args(a, args, -1, j);
		}
		else
		{
			n = ft_atoi(argv[i]);
			if ((!ft_isint(argv[i]) || !chk_dup(*a, n)) && ft_printf("Error\n"))
				return ;
			push(a, &n, sizeof(int));
		}
	}
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
