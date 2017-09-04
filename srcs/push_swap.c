/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 22:54:12 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/04 16:07:15 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	del(void *content, size_t size)
{
	if (content)
		free(content);
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
			free(args);
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

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_args(&a, argv, 0, argc);
	sort(&a, &b, argc - 1);
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
	exit(0);
}
