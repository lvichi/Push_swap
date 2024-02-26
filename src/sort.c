/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:11:38 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/23 16:19:25 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_list **list, char type);
void		transfer_cheap(t_list **a, t_list **b, int size_a, int size_b);
static void	calculate_cost(t_list *a, t_list *b, int size_a, int size_b);
static void	transfer(t_list **a, t_list **b, t_list *cheapest);
static int	transfer_formula(t_list *list);

void	sort_three(t_list **list, char type)
{
	if (!(*list))
		return ;
	if (type == 'a' && (*list)->r_v > ((*list)->next)->r_v
		&& (*list)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "rra");
	if (type == 'a' && (*list)->r_v < ((*list)->next)->r_v
		&& ((*list)->next)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "rra");
	if (type == 'a' && (*list)->r_v > ((*list)->next)->r_v)
		op_list(list, NULL, "sa");
	if (type == 'a' && (*list)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "ra");
	if (type == 'b' && (*list)->r_v < ((*list)->next)->r_v
		&& (*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if (type == 'b' && (*list)->r_v > ((*list)->next)->r_v
		&& ((*list)->next)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if (type == 'b' && (*list)->r_v < ((*list)->next)->r_v)
		op_list(NULL, list, "sb");
	if (type == 'b' && (*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rb");
}

void	transfer_cheap(t_list **a, t_list **b, int size_a, int size_b)
{
	t_list	*cheapest;
	int		i;

	cheapest = (*a);
	i = 0;
	calculate_cost(*a, *b, size_a, size_b);
	if ((int)cheapest->r_v >= (size_a + size_b - 3))
		cheapest->transfer_cost_b = 999;
	while (i++ < size_a)
	{
		if (transfer_formula(*a) < transfer_formula(cheapest)
			&& (int)(*a)->r_v < (size_a + size_b - 3))
			cheapest = (*a);
		(*a) = (*a)->next;
	}
	transfer(a, b, cheapest);
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
		a->transfer_cost_a = j;
		if (j > size_a / 2)
			a->transfer_cost_a = j - size_a;
		a->transfer_cost_b = find_next(b, size_a + size_b, min, max);
		a = a->next;
	}
}

static void	transfer(t_list **a, t_list **b, t_list *cheapest)
{
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
	if ((*a)->transfer_cost_b > 0)
		while ((*a)->transfer_cost_b--)
			op_list(a, b, "rb");
	else if ((*a)->transfer_cost_b < 0)
		while ((*a)->transfer_cost_b++)
			op_list(a, b, "rrb");
	op_list(a, b, "pb");
}

static int	transfer_formula(t_list *list)
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
			return (list->transfer_cost_a * -1);
		else
			return (list->transfer_cost_b * -1);
	}
	if (list->transfer_cost_a < 0)
		return ((list->transfer_cost_a * -1) + list->transfer_cost_b);
	else
		return (list->transfer_cost_a + (list->transfer_cost_b * -1));
}
