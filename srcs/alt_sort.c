/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:31:35 by bpuschel          #+#    #+#             */
/*   Updated: 2017/09/30 13:06:34 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*int			ft_bsearch(int *arr, int key, int size)
{
	int left;
	int right;
	int mid;

	left = 0;
	right = size - 1;
	if (arr[left] > arr[right])
		return (-1);
	while (left != right)
	{	
		if (arr[left] == key)
			return (left);
		if (arr[right] == key)
			return (right);
		mid = (left + right) / 2;
		if (arr[mid] == key)
			return (mid);
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}*/

/*static void find_max(t_list *a, int *max, int *size, int *i_max)
{
	t_list *curr;

	curr = a;
	*max = CUR(curr);
	*size = 0;
	*i_max = 0;
	while (curr)
	{
		if (CUR(curr) > *max)
		{
			*max = CUR(curr);
			*i_max = *size;
		}
		curr = curr->next;
		*size = *size + 1;
	}
	*i_max = (*i_max > (*size / 2)) ? ABS(*size - *i_max + 1) : *i_max;
}

static void find_min(t_list *a, int *min, int *size, int *i_min)
{
	t_list *curr;

	curr = a;
	*min = CUR(curr);
	*size = 0;
	*i_min = 0;
	while (curr)
	{
		if (CUR(curr) < *min)
		{
			*min = CUR(curr);
			*i_min = *size;
		}
		curr = curr->next;
		*size = *size + 1;
	}
	*i_min = (*i_min > (*size / 2)) ? ABS(*size - *i_min + 1) : *i_min;
}

static void max_sort(t_list **a, t_list **b)
{
	int	max;
	int	b_size;
	int	i_max;

	while (*b)
	{
		find_max(*b, &max, &b_size, &i_max);
		if ((*b)->next && max == NXT(*b))
			print_cmd("sb", a, b, 1);
		else
		{
			while (CUR(*b) != max)
			{
				if (i_max < (b_size / 2))
					print_cmd("rb", a, b, 1);
				else
					print_cmd("rrb", a, b, 1);
			}
		}
		print_cmd("pa", a, b, 1);
	}
}*/

/*static void next_region(t_list **a, t_list **b, int i, int size)
{
	if (i < size / 2)
	{
		if (!validate(*a, NULL) && !validate(*b, NULL))
			print_cmd("rr", a, b, 2);
		else if (!validate(*a, NULL))
			print_cmd("ra", a, b, 2);
		else if (!validate(*b, NULL))
			print_cmd("rb", a, b, 2);
	}
	else
	{
		if (!validate(*a, NULL) && !validate(*b, NULL))
			print_cmd("rr", a, b, 1);
		else if (!validate(*a, NULL))
			print_cmd("ra", a, b, 1);
		else if (!validate(*b, NULL))
			print_cmd("rb", a, b, 1);
	}
}*/

/*static void	swap_qs(t_list **a, t_list **b, int left, int right)
{
	print_cmd("ra", a, b, right);
	print_cmd("pb", a, b, 1);
	print_cmd("rra", a, b, right - left);
	print_cmd("pb", a, b, 1);
	print_cmd("sb", a, b, 1);
	print_cmd("pa", a, b, 1);
	print_cmd("ra", a, b, right - left);
	print_cmd("pa", a, b, 1);
	print_cmd("rra", a, b, right - 1);
}

static int	partition(t_list **a, t_list **b, int lo, int hi)
{
	int		i;
	int		j;
	int		start;
	int		*arr;
	t_list	*curr;

	curr = *a;
	i = -1;
	while (curr && ++i)
		curr = curr->next;
	arr = ft_memalloc(i * sizeof(int));
	list_to_arr(a, &arr);
	start = arr[0];
	print_cmd("ra", a, b, lo);
	j = lo - 1;
	i = lo;
	while (++j < hi)
	{
		if (arr[j] < arr[hi])
			swap_qs(a, b, i++, j);
	}
	if (arr[hi] < arr[i + 1])
		swap_qs(a, b, i + 1, hi);
	while (CUR(*a) != start)
		print_cmd("ra", a, b, 1);
	free(arr);
	return (i + 1);
}*/

/*static void	stack_sort(t_list **a, t_list **b)
{
*	int		end;
	char	*rotate;

	while (!validate(*a, *b))
	{
		i = ft_bsearch(sorted, CUR(*a), size);
		if (i > 0 && NXT(*a) <= sorted[i - 1])
			print_cmd("sa", a, b);
		else if (i < size - 1 && NXT(*a) != sorted[i + 1])
		{
			print_cmd("pb", a, b);
			while (CUR(*a) != sorted[i + 1])
				print_cmd("ra", a, b);
			print_cmd("pa", a, b);
		}
		print_cmd("rra", a, b);
	}
	while (*a)
	{
		if (!(*b))
			print_cmd("pb", a, b);
		if (!(*b)->next)
		{
			print_cmd("pb", a, b);
			if (CUR(*b) < NXT(*b))
				print_cmd("rb", a, b);
		}
		end = CUR(*b);
		rotate = (NXT(*b) < CUR(*b)) ? "rb" : "rrb";
		if (CUR(*b) > CUR(*a))
			print_cmd(rotate, a, b);
		while (CUR(*b) > CUR(*a) && CUR(*b) != end)
			print_cmd(rotate, a, b);
		print_cmd("pb", a, b);
		while (!rev_validate(*b))
			print_cmd(rotate, a, b);
	}
	while (*b)
		print_cmd("pa", a, b);*/
/*	int		i;
	
	i = -1;
	while (++i < size)
	{
		if (CUR(*a) == helper[i])
			print_cmd("pb", a, b);
		else
		{
			while (CUR(*a) != helper[i])
			{
				print_cmd("sa", a, b);
				if (CUR(*a) != helper[i])
				print_cmd("ra", a, b);
			}
			print_cmd("pb", a, b);
		}
	}
	while (*b)
		print_cmd("pa", a, b);*/
/*	Best one
 *	int	min;
	int	a_size;
	int	i_min;

	while (!validate(*a, *b))
	{
		find_min(*a, &min, &a_size, &i_min);
		if (min == NXT(*a))
			print_cmd("sa", a, b, 1);
		else
		{
			while (CUR(*a) != min)
			{
				if (i_min < (a_size / 2))
					print_cmd("ra", a, b, 1);
				else
					print_cmd("rra", a, b, 1);
			}
		}
		if (validate(*a, *b) || (validate(*a, NULL) && rev_validate(*b)))
			break ;
		print_cmd("pb", a, b, 1);
	}
	while (*b)
		print_cmd("pa", a, b, 1);*/
	//int nb;
	//int xb;
	//min_max(*b, &nb, &xb);
	/*while (!validate(*a, NULL) && !validate(*b, NULL))
	{
		if (BALT(*a, *b) && !END(*a, xa, na) && !END(*b, xb, nb))
			print_cmd("ss", a, b, 1);
		else if (GT(*a) && !END(*a, xa, na))
			print_cmd("sa", a, b, 1);
		else if (GT(*b) && !END(*b, xb, nb))
			print_cmd("sb", a, b, 1);
		next_region(a, b, i, size);
		i++;
	}
	while (!validate(*a, *b))
	{
		na = (*b != NULL && na > CUR(*b)) ? CUR(*b) : na;
		xa = (*b != NULL && xa < CUR(*b)) ? CUR(*b) : xa;
		if (*b != NULL && xa == CUR(*b))
		{
			while (CUR(*a) != na)
				print_cmd("rra", a, b, 1);
			print_cmd("pa", a, b, 1);
			print_cmd("ra", a, b, 1);
		}
		else if (*b != NULL && na == CUR(*b))
		{
			while (CUR(*a) != xa)
				print_cmd("rra", a, b, 1);
			print_cmd("ra", a, b, 1);
			print_cmd("pa", a, b, 1);
		}
		else if (*b != NULL)
		{
			while (CUR(*a) < CUR(*b))
				print_cmd("ra", a, b, 1);
			print_cmd("pa", a, b, 1);
		}
		else
			alt_sort(a, b, size);
	}*/
	/*int p;

	if (lo < hi)
	{
		p = partition(a, b, lo, hi);
		stack_sort(a, b, lo, p - 1);
		stack_sort(a, b, p + 1, hi);
	}*/


/*static void	bottom_up(int *a, int **b, int w, int size)
{
	int	i;
	int	j;
	int	k;
	int	e;

	i = 0;
	while (i < size)
	{
		j = MIN(i + w, size);
		e = MIN(i + (2 * w), size);
		k = i - 1;
		while (++k < e)
			b[0][k] = (i < j && (j >= e || (a[i] <= a[j]))) ? a[i++] : a[j++];
		i = (e == size) ? i : e - (2 * w);
		i += 2 * w;
	}
}

void		merge_sort(t_list **a, t_list **b, int size)
{
	int		w;
	int		*sorted;
	int		*helper;

	sorted = ft_memalloc(size * sizeof(int));
	helper = ft_memalloc(size * sizeof(int));
	list_to_arr(a, &sorted);
	w = 1;
	while (w < size)
	{
		bottom_up(sorted, &helper, w, size);
		stack_sort(a, b, helper, size);
		if (validate(*a, *b))
			break;
		ft_memcpy(sorted, helper, size * sizeof(int));
		w *= 2;
	}
	free(sorted);
	free(helper);
}*/

void		alt_sort(t_list **a, int size)
{
//	print_cmd("pb", a, b, size / 2);
//	merge_sort(a, b, size);
//	max_sort(a, b);
//	stack_sort(a, b);
	char **cmd;
	int *a_arr;
	int i;

	cmd = ft_memalloc(11 * sizeof(char *));
	cmd[0] = ft_strdup("sa");
	cmd[1] = ft_strdup("ra");
	cmd[2] = ft_strdup("rra");
	cmd[3] = ft_strdup("pb");
	cmd[4] = ft_strdup("pa");
	cmd[5] = ft_strdup("sb");
	cmd[6] = ft_strdup("rb");
	cmd[7] = ft_strdup("rrb");
	cmd[8] = ft_strdup("ss");
	cmd[9] = ft_strdup("rr");
	cmd[10] = ft_strdup("rrr");
	a_arr = ft_memalloc(size * sizeof(int));
	list_to_arr(a, &a_arr);
	evolve(a_arr, cmd, size);
	free(a_arr);
	i = -1;
	while (++i < 11)
		free(cmd[i]);
	free(cmd);
}
