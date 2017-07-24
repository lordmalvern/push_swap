/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 19:32:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/07/23 17:57:25 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	validate(t_list *a, t_list *b)
{
	t_list	*curr;
	int		prev;

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

static int	chk_dup(t_list *stack, int n)
{
	t_list	*curr;

	curr = stack;
	while (curr != NULL && n != *((int *)curr->content))
		curr = curr->next;
	if (curr != NULL)
		return (0);
	return (1);
}

static void	parse(t_list **a, t_list **b)
{
	char	*cmd;

	while (get_next_line(0, &cmd))
		parse_cmd(cmd, a, b);
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

int			main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		n;

	a = ft_lstnew(NULL, 0);
	b = ft_lstnew(NULL, 0);
	i = argc;
	if (argc == 1)
		return (0);
	while (--i > 0)
	{
		n = ft_atoi(argv[i]);
		if ((!ft_isint(argv[i]) || !chk_dup(a, n)) && ft_printf("Error\n"))
			return (0);
		push(&a, &n, sizeof(int));
	}
	parse(&a, &b);
	ft_lstdel(&a, del);
	ft_lstdel(&b, del);
	return (0);
}
