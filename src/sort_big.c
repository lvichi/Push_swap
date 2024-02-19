/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:27:11 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/16 16:15:01 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_big(t_list **a, t_list **b, size_t size);
static void		first_sort(t_list **a, t_list **b, size_t size, size_t i);
static void		move_r(t_list **a, t_list **b, size_t size, size_t range);
static size_t	find_next(t_list **list, size_t size, size_t min, size_t max, int direction);
static void		move_r_back(t_list **a, t_list **b, size_t size, size_t range);

void	sort_big(t_list **a, t_list **b, size_t size)
{
	size_t	range;

	range = size / 10;
	if (!check_sort(*a, 'a'))
	{
		first_sort(a, b, size, 0);
		move_r(a, b, size, range);
		range = 1;
		move_r_back(a, b, size, range);
	}
}

static void	first_sort(t_list **a, t_list **b, size_t size, size_t i)
{
	while (*a && size)
	{
		op_list(a, b, "pb");
		if (*b && (*b)->r_v < (size / 2))
			op_list(a, b, "rb");
	}
	while (*b && size && i++ < (size / 2))
	{
		op_list(a, b, "pa");
		if (*a && (*a)->r_v > (size - size / 4))
			op_list(a, b, "ra");
	}
	while (*b && size && i < size - size / 4)
	{
		if ((*b)->r_v >= size / 4 && i++)
			op_list(a, b, "pa");
		else if (find_next(b, size, (size / 4), (size / 2), 1) < (size / 4))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
	}
	while (*b)
		op_list(a, b, "pa");
}

static size_t	find_next(t_list **list, size_t size, size_t min, size_t max, int direction)
{
	t_list	*temp_list;
	size_t	count;

	temp_list = *list;
	count = 0;
	while (size--)
	{
		count++;
		if (temp_list->r_v >= min && temp_list->r_v < max)
			return (count);
		if (direction)
			temp_list = temp_list->next;
		else
			temp_list = temp_list->prev;
	}
	return (0);
}

static void	move_r(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;

	count = 0;
	limit = range;
	while (*a && size)
	{
		if ((*a)->r_v < limit)
		{
			op_list(a, b, "pb");
			count++;
		}
		else if (find_next(a, size, 0, limit, 1) < find_next(a, size, 0, limit, 0))
			op_list(a, b, "ra");
		else
			op_list(a, b, "rra");
		if (count == limit)
			limit = limit + range;
	}
}

static void	move_r_back(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;

	count = size;
	limit = size - range;
	while (*b && size)
	{
		if ((*b)->r_v >= limit)
		{
			op_list(a, b, "pa");
			count--;
		}
		else if (find_next(b, size, limit, size, 1) < (count / 2))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
		if (count <= limit && range > 0 && limit > range)
			limit = limit - range;
		else if (count <= limit)
			limit = limit - 1;
	}
}
