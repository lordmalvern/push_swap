/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 22:54:12 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/26 20:38:08 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int			main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_args(&a, argv, 0, argc);
	if (argc - 1 <= 7)
		sort(&a, &b, argc - 1);
	else
		alt_sort(&a, argc - 1);
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
	exit(0);
}
