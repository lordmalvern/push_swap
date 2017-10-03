/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:31:59 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/21 18:42:19 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void		parse_args(t_list **a, char **argv, int debug, int i)
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
				exit(-1);
			push(a, &n, sizeof(int));
		}
	}
}
