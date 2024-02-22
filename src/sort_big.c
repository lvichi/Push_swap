/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:11:38 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/22 19:18:20 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_big(t_list **a, t_list **b);
static void		sort_three(t_list **list);
static void		calculate_cost(t_list *a, t_list *b, int size_a, int size_b);
static int		find_next(t_list *list, int size, int min, int max);
static void		transfer_cheap(t_list **a, t_list **b, int size_a, int size_b);
static void		transfer(t_list **a, t_list **b);
static int		transfer_formula(t_list *list);

void	sort_big(t_list **a, t_list **b)
{
	while (count_list(*b) != 3)
		op_list(a, b, "pb");
	sort_three(b);
	while (*a)
		transfer_cheap(a, b, (int)count_list(*a), (int)count_list(*b));
	while (*b)
		op_list(a, b, "pa");
	if (find_next(*a, count_list(*a), 0, count_list(*a)) > 0)
		while ((*a)->r_v != 0)
			op_list(a, b, "ra");
	else
		while ((*a)->r_v != 0)
			op_list(a, b, "rra");
}

static void	sort_three(t_list **list)
{
	if ((*list)->r_v < ((*list)->next)->r_v
			&& (*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if ((*list)->r_v > ((*list)->next)->r_v
			&& ((*list)->next)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if ((*list)->r_v < ((*list)->next)->r_v)
		op_list(NULL, list, "sb");
	if ((*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rb");
}

static void	calculate_cost(t_list *a, t_list *b, int size_a, int size_b)
{
	int	min;
	int	max;
	int	i;
	int	j;

	j = -1;
	while (++j < size_a)
	{
		min = -1;
		max = size_a + size_b;
		i = -1;
		while (++i < size_b)
		{
			if ((int)b->r_v > min && b->r_v < a->r_v)
				min = b->r_v;
			if ((int)b->r_v < max && b->r_v > a->r_v)
				max = b->r_v;
			b = b->next;
		}
		if (j <= size_a / 2)
			a->transfer_cost_a = j;
		else
			a->transfer_cost_a = j - size_a;
		a->transfer_cost_b = find_next(b, size_a + size_b, min, max);
		a = a->next;
	}
}

static int	find_next(t_list *list, int size, int min, int max)
{
	int		i;
	int		size_list;

	size_list = (int)count_list(list);
	i = -1;
	while (++i < size_list && size)
	{
		if (((int)list->r_v == min && (int)(list->prev)->r_v == max)
			|| (min == -1 && (int)(list->prev)->r_v == max)
			|| (max == size && (int)list->r_v == min))
			break ;
		list = list->next;
	}
	if (i > (size_list / 2))
		i = i - size_list;
	return (i);
}

static void		transfer_cheap(t_list **a, t_list **b, int size_a, int size_b)
{
	t_list	*cheapest;
	size_t	i;

	cheapest = (*a);
	i = 0;
	calculate_cost(*a, *b, size_a, size_b);
	while (i++ < count_list(*a))
	{
		if (transfer_formula(*a) < transfer_formula(cheapest))
			cheapest = (*a);
		(*a) = (*a)->next;
	}
	while ((*a) != cheapest)
	{
		if (cheapest->transfer_cost_a < 0 && cheapest->transfer_cost_b < 0)
		{
			op_list(a, b, "rrr");
			cheapest->transfer_cost_b++;
		}
		else if (cheapest->transfer_cost_a > 0 && cheapest->transfer_cost_b > 0)
		{
			op_list(a, b, "rr");
			cheapest->transfer_cost_b--;
		}
		else if (cheapest->transfer_cost_a < 0)
			op_list(a, b, "rra");
		else
			op_list(a, b, "ra");
	}
	transfer(a, b);
}

static void	transfer(t_list **a, t_list **b)
{
	while ((*a)->transfer_cost_b)
	{
		if ((*a)->transfer_cost_b > 0)
		{
			op_list(a, b, "rb");
			(*a)->transfer_cost_b--;
		}
		else
		{
			op_list(a, b, "rrb");
			(*a)->transfer_cost_b++;
		}
	}
	op_list(a, b, "pb");
}

static int		transfer_formula(t_list *list)
{
	if (list->transfer_cost_a >= 0 && list->transfer_cost_b >= 0)
	{
		if (list->transfer_cost_a > list->transfer_cost_b)
			return (list->transfer_cost_a);
		else
			return (list->transfer_cost_b);
	}
	if (list->transfer_cost_a < 0 && list->transfer_cost_b < 0)
	{
		if (list->transfer_cost_a < list->transfer_cost_b)
			return (ft_abs(list->transfer_cost_a));
		else
			return (ft_abs(list->transfer_cost_b));
	}
	return (ft_abs(list->transfer_cost_a) + ft_abs(list->transfer_cost_b));
}
