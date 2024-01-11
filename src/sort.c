/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:23 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/11 23:24:28 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **a, t_list **b, size_t size, int type);

static void	sort(t_list **a, t_list **b, size_t size, int type)
{
	if (type == 1)
	{
		if (*a && (*a)->next != *a && (*a)->r_v > ((*a)->next)->r_v
			&& (*a)->r_v != size - 1 && *b && (*b)->next != *b
			&& (*b)->r_v < ((*b)->next)->r_v && (*b)->r_v != 0)
			op_list(a, b, "ss");
		else if (*a && (*a)->next != *a && (*a)->r_v > ((*a)->next)->r_v
			&& (*a)->r_v != size - 1)
			op_list(a, b, "sa");
		else if (*b && (*b)->next != *b && (*b)->r_v < ((*b)->next)->r_v
			&& (*b)->r_v != 0)
			op_list(a, b, "sb");
		return ;
	}
	if (*a && (*a)->next != *a && (*a)->r_v > ((*a)->next)->r_v
		&& (*a)->r_v != size - 1 && *b && (*b)->next != *b
		&& (*b)->r_v < ((*b)->next)->r_v && (*b)->r_v != 0)
		op_list(a, b, "ss");
	else if (*a && (*a)->next != *a && (*a)->r_v > ((*a)->next)->r_v
		&& ((*a)->next)->r_v != 0)
		op_list(a, b, "sa");
	else if (*b && (*b)->next != *b && (*b)->r_v < ((*b)->next)->r_v
		&& ((*b)->next)->r_v != size - 1)
		op_list(a, b, "sb");
}

static void	move(t_list **a, t_list **b, size_t size, size_t count, int type)
{
	size_t	pb_count;

	pb_count = 0;
	if (!(size % 2) && type == 2)
		pb_count++;
	while (pb_count < count)
	{
		sort(a, b, size, 1);
		if ((*a)->r_v < count && type == 1)
		{
			op_list(a, b, "pb");
			pb_count++;
		}
		else if ((*a)->r_v > count && type == 2)
		{
			op_list(a, b, "pb");
			pb_count++;
		}
		else
			op_list(a, b, "ra");
	}
}

static size_t	find_next(t_list **list, size_t size, size_t min, size_t max)
{
	t_list *temp_list;
	size_t	count;

	temp_list = *list;
	count = 0;
	while (size--)
	{
		count++;
		if (temp_list->r_v >= min && temp_list->r_v < max)
			return (count);
		temp_list = temp_list->next;
	}
	return (0);
}

static void	move_limit(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;

	count = 0;
	limit = range;
	while (*a && size > 2 && limit)
	{
		if ((*a)->r_v < limit)
		{
			op_list(a, b, "pb");
			count++;
		}
		else if (find_next(a, size, 0, limit) < ((size - count) / 2))
			op_list(a, b, "ra");
		else
			op_list(a, b, "rra");
		if (count == limit)
			limit = limit + range;
	}
	sort(a, b, size, 1);
}

static void	move_limit_back(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;

	count = size;
	limit = size - range;
	while (*b && size > 2)
	{
		if ((*b)->r_v >= limit)
		{
			op_list(a, b, "pa");
			count--;
		}
		else if (find_next(b, size, limit, size - 1) < (count / 2))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
		if (count <= limit && range > 0 && limit >= range)
			limit = limit - range;
		else if (count <= limit)
			limit = limit - 1;
	}
	sort(a, b, size, 1);
}

static void	sort_min(t_list **a, t_list **b, size_t size)
{
	size_t	i;

	while (!check_sort(*a, 'a') && size < 4)
	{
		sort(a, b, size, 2);
		op_list(a, b, "ra");
	}
	while (!check_sort(*a, 'a'))
	{
		move(a, b, size, size / 2, 1);
		rotate(a, b, size, 1);
		i = 0;
		while (i++ < size / 2)
		{
			sort(a, b, size, 1);
			op_list(a, b, "pa");
		}
		if (check_sort(*a, 'a'))
			break ;
		move(a, b, size, (size / 2), 2);
		rotate(a, b, size, 2);
		i = 0;
		while (i++ < (size / 2))
		{
			op_list(a, b, "pa");
		}
		rotate(a, b, size, 2);
		print_lists(*a, *b);
	}
}

static void	sort_big(t_list **a, t_list **b, size_t size)
{
	size_t	limit;
	
	limit = size / 10;
	if (!check_sort(*a, 'a') && limit > 10)
	{
		move_limit(a, b, size, limit);
		limit = 1;
		move_limit_back(a, b, size, limit);
	}
}

t_list	*sort_list(t_list *a)
{
	t_list	*b;
	size_t	size;

	b = NULL;
	size = count_list(a);
	sort_big(&a, &b, size);
	sort_min(&a, &b, size);
	print_lists(a, b);
	if (check_sort(a, 'a'))
		write(1, "\nOK!\n", 5);
	else
		write(1, "\nKO\n", 4);
	print_moves();//					delete
	free_list(b);
	return (a);
}

static void	rotate(t_list **a, t_list **b, size_t size, int type)
{
	if (type == 1)
	{
		while (size > 1 && ((*a)->r_v != size / 2 || ((*b)->prev)->r_v != 0))
		{
			sort(a, b, size, 1);
			if ((*a)->r_v != size / 2 && ((*b)->prev)->r_v != 0)
				op_list(a, b, "rr");
			else if ((*a)->r_v != size / 2)
				op_list(a, b, "ra");
			else if (((*b)->prev)->r_v != 0)
				op_list(a, b, "rb");
		}
		return ;
	}
	while ((*a && ((*a)->r_v != 0)) || (*b && (*b)->r_v != size - 1))
	{
		sort(a, b, size, 2);
		if (*a && *b && (*a)->r_v != 0 && (*b)->r_v != size - 1)
			op_list(a, b, "rr");
		else if (*a && (*a)->r_v != 0)
			op_list(a, b, "ra");
		else if (*b && (*b)->r_v != size - 1)
			op_list(a, b, "rb");
	}
}