/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:23 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/16 14:31:54 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_small(t_list **a, t_list **b, size_t size);
static void	rotate(t_list **a, t_list **b, size_t size);
static void	sort(t_list **a, t_list **b, size_t size, int type);
static void	move_first_half(t_list **a, t_list **b, size_t size);
static void	move_second_half(t_list **a, t_list **b, size_t size);

void	sort_small(t_list **a, t_list **b, size_t size)
{
	while (!check_sort(*a, 'a') && size < 4)
	{
		sort(a, b, size, 2);
		op_list(a, b, "rra");
	}
	while (!check_sort(*a, 'a'))
	{
		move_first_half(a, b, size);
		if (check_sort(*a, 'a'))
			break ;
		move_second_half(a, b, size);
	}
}

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

static void	move_first_half(t_list **a, t_list **b, size_t size)
{
	size_t	pb_count;

	pb_count = 0;
	while (pb_count < size - size / 2)
	{
		if (*a && (*a)->r_v < size - size / 2)
		{
			op_list(a, b, "pb");
			pb_count++;
		}
		else
			op_list(a, b, "ra");
	}
	rotate(a, b, size);
	while (*b)
	{
		sort(a, b, size, 1);
		op_list(a, b, "pa");
	}
}

static void	move_second_half(t_list **a, t_list **b, size_t size)
{
	size_t	pb_count;
	size_t	count;

	pb_count = 0;
	count = size / 2;
	if (size % 2)
		count = count + 1;
	while (pb_count < count)
	{
		if (*a && (*a)->r_v >= size / 2)
		{
			op_list(a, b, "pb");
			pb_count++;
		}
		else
			op_list(a, b, "ra");
		sort(a, b, size, 2);
	}
	while (*b)
	{
		sort(a, b, size, 2);
		op_list(a, b, "pa");
	}
}

static void	rotate(t_list **a, t_list **b, size_t size)
{
	while ((*a && (*a)->r_v != size - size / 2) || (*b
			&& ((*b)->prev)->r_v != 0))
	{
		sort(a, b, size, 1);
		if (*a && *b && (*a)->r_v != size - size / 2 && ((*b)->prev)->r_v != 0)
			op_list(a, b, "rr");
		else if (*a && (*a)->r_v != size - size / 2)
			op_list(a, b, "ra");
		else if (*b && ((*b)->prev)->r_v != 0)
			op_list(a, b, "rb");
	}
	return ;
}
