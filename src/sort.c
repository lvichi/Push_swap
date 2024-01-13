/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skinners77 <lvichi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:27:11 by skinners77        #+#    #+#             */
/*   Updated: 2024/01/13 23:32:46 by skinners77       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_big(t_list **a, t_list **b, size_t size);
static void		move_r(t_list **a, t_list **b, size_t size, size_t range);
static size_t	find_next(t_list **list, size_t size, size_t min, size_t max);
static void		move_r_back(t_list **a, t_list **b, size_t size, size_t range);

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

static void	sort_big(t_list **a, t_list **b, size_t size)
{
	size_t	range;

	range = size / 10;
	while (!check_sort(*a, 'a') && range > 2)
	{
		move_r(a, b, size, range);
		range = range / 2;
		if (range <= 5)
			range = 2;
		move_r_back(a, b, size, range);
		range = range / 2;
	}
}

static size_t	find_next(t_list **list, size_t size, size_t min, size_t max)
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
		temp_list = temp_list->next;
	}
	return (0);
}

static void	move_r(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;

	count = 0;
	limit = range;
	while (*a)
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
		else if (find_next(b, size, limit, size - 1) < (count / 2))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
		if (count <= limit && range > 0 && limit >= range)
			limit = limit - range;
		else if (count <= limit)
			limit = limit - 1;
		if (range == 2)
			sort(a, b, size, 2);
	}
}
