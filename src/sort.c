/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:23 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/09 02:51:34 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort(t_list **a, t_list **b, size_t size, int type)
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

static void move(t_list **a, t_list **b, size_t size, size_t count, int type)
{
	size_t	pb_count;

	pb_count = 0;
	if (!(size % 2) && type == 2)
		pb_count++;
	while (pb_count < count)
	{
		sort(a, b, size, type);
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

static void	rotate(t_list **a, t_list **b, size_t size, int type)
{
	if (type == 1)
	{
		while (size > 1 && ((*a)->r_v != size / 2 || ((*b)->prev)->r_v != 0))
		{
			sort(a, b, size, type);
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
		sort(a, b, size, type);
		if (*a && *b && (*a)->r_v != 0 && (*b)->r_v != size - 1)
			op_list(a, b, "rr");
		else if (*a && (*a)->r_v != 0)
			op_list(a, b, "ra");
		else if (*b && (*b)->r_v != size - 1)
			op_list(a, b, "rb");
	}
}

t_list	*sort_list(t_list *a)
{
	t_list	*b;
	size_t	size;
	size_t	i;

	b = NULL;
	size = count_list(a);
	//print_lists(a, b);

	while (!check_sort(a, 'a'))
	{
		move(&a, &b, size, size / 2, 1);
		//print_lists(a, b);

		rotate(&a, &b, size, 1);
		//print_lists(a, b);
		
		i = 0;
		while(i++ < size / 2)
		{
			sort(&a, &b, size, 1);
			op_list(&a, &b, "pa");
		}
		//print_lists(a, b);

		if (check_sort(a, 'a'))
			break;

		move(&a, &b, size, (size / 2), 2);
		//print_lists(a, b);

		rotate(&a, &b, size, 2);
		//print_lists(a, b);
		
		i = 0;
		while(i++ < (size / 2))
		{
			op_list(&a, &b, "pa");
		}
		//print_lists(a, b);
		
		rotate(&a, &b, size, 2);
		//print_lists(a, b);
	}

	if (check_sort(a, 'a'))
		write(1, "\nOK!\n", 5);
	else
		write(1, "\nKO\n", 4);
	
	print_moves();//					delete
	free_list(b);
	return (a);
}
