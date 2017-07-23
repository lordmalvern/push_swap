/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:32:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/22 20:47:11 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int validate(t_list *a, t_list *b)
{
	t_list *curr;
	int prev;

	if (a->content == NULL || b->content != NULL)
		return (0);
	curr = a;
	prev = *((int *)curr->content);
	while (curr != NULL && prev < *((int *)curr->content))
		{
			prev = *((int *)curr->content);
			curr = curr->next;
		}
	if (curr != NULL)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int i;
	int n;
	char *cmd;

	a = ft_lstnew(NULL, 0);
	b = ft_lstnew(NULL, 0);
	i = argc;
	while (--i > 0)
	{
		n = ft_atoi(argv[i]);
		push(&a, &n, sizeof(int));
	}
	while (get_next_line(0, &cmd))
		parse_cmd(cmd, &a, &b);
	if (validate(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
