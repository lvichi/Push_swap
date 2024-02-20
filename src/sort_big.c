/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:11:38 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/20 23:00:29 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_big(t_list **a, t_list **b, size_t size);
static void		sort_three(t_list **list);
static void		calculate_cost(t_list *a, t_list *b);
static int		find_next(t_list *list, size_t min, size_t max);
//static void		transfer_cheapest(t_list **a, t_list **b);
//static void		transfer(t_list **a, t_list **b);

void	sort_big(t_list **a, t_list **b, size_t size)
{
	while (count_list(*b) != 3 && size)
		op_list(a, b, "pb");
	sort_three(b);
	if (*a)
	{
		calculate_cost(*a, *b);
		//transfer_cheapest(a, b);
	}
	print_list(*a, *b);
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

static void	calculate_cost(t_list *a, t_list *b)
{
	size_t	min;
	size_t	max;
	size_t	i;
	int		j;

	j = -1;
	while (++j < (int)count_list(a))
	{
		min = 0;
		max = count_list(a) + count_list(b) - 1;
		i = -1;
		while (++i < count_list(b))
		{
			if (b->r_v > min && b->r_v < a->r_v)
				min = b->r_v;
			b = b->next;
		}
		i = -1;
		while (++i < count_list(b))
		{
			if (b->r_v < max && b->r_v > a->r_v)
				max = b->r_v;
			b = b->next;
		}
		if (j <= (int)count_list(a) / 2)
			a->transfer_cost_a = j;
		else
			a->transfer_cost_a = j - count_list(a);
		a->transfer_cost_b = find_next(b, min, max);
		printf("%ld\tMin: %ld -- Max: %ld\n", a->r_v, min, max);
		a = a->next;
	}
}

static int	find_next(t_list *list, size_t min, size_t max)
{
	int		i;
	int		size;

	size = (int)count_list(list);
	i = -1;
	while (++i < size)
	{
		if (list->r_v >= min && list->r_v < max)
			break ;
		list = list->next;
	}
	if (i > (size / 2))
		i = i - size;
	printf("\nfind_next: %d\n", i);
	return (i);
}

/*static void		transfer_cheapest(t_list **a, t_list **b)
{
	int		cheapest;
	size_t	i;
	int		reverse;

	cheapest = (*a)->transfer_cost;
	i = 0;
	reverse = 0;
	while (i++ < count_list(*a))
	{
		if ((*a)->transfer_cost > 0 && (*a)->transfer_cost < cheapest)
		{
			cheapest = (*a)->transfer_cost;
			if (i > count_list(*a) / 2)
				reverse = 1;
		}
		(*a) = (*a)->next;
	}
	while ((*a)->transfer_cost != cheapest)
	{
		if (reverse)
			op_list(a, b, "rra");
		else
			op_list(a, b, "ra");
	}
	printf("\ntransfer_cheapest: %ld\n", (*a)->r_v);
}*/

/*static void	transfer(t_list **a, t_list **b)
{

}*/