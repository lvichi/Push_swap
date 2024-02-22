/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:27:11 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/21 19:14:33 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_big_2(t_list **a, t_list **b, size_t size);
static void		first_sort(t_list **a, t_list **b, size_t size, size_t i);
static void		move_r(t_list **a, t_list **b, size_t size, size_t range);
static size_t	find_next(t_list **list, size_t min, size_t max, int direction);
//static void		new_sort(t_list **a, t_list **b);
static void		move_r_back(t_list **a, t_list **b, size_t size, size_t range);
static void		new_sort_2(t_list **a, t_list **b, int reverse);


/*static int	ft_putnbr(long nbr)
{
	char	c;
	int		size;

	size = 0;
	if (nbr < 0)
	{
		size += write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		size += ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	c = nbr + '0';
	size += write(1, &c, 1);
	return (size);
}*/


void	sort_big_2(t_list **a, t_list **b, size_t size)
{
	size_t	range;

	range = size / 4;
	if (!check_sort(*a, 'a'))
	{
		first_sort(a, b, 0, 0);
		//range /= 5;
		move_r(a, b, size, range);
		//new_sort_2(a, b, 0);
		new_sort_2(a, b, 1);
		range /= 5;
		move_r_back(a, b, 0, 1);
		range /= 2;
		//if (range < 15)
		range = 1;
	}
	while (*b)
		op_list(a, b, "pa");
}

static void	first_sort(t_list **a, t_list **b, size_t size, size_t i)
{
	while (*a && size)
	{
		op_list(a, b, "pb");
		if (*b && (*b)->r_v < (size / 2))
			op_list(a, b, "rb");
	}
	//size = 0;
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
		else if (find_next(b, (size / 4), (size / 2), 1) < (size / 4))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
	}
	while (*b && size)
		op_list(a, b, "pa");
}

static size_t	find_next(t_list **list, size_t min, size_t max, int direction)
{
	t_list	*temp_list;
	int		count;
	size_t	size;

	size = count_list(*list);
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

/*static void	new_sort(t_list **a, t_list **b)
{
	if (*a && *b && (*a)->r_v > ((*a)->next)->r_v
		&& (*b)->r_v < ((*b)->next)->r_v)
		op_list(a, b, "ss");
	else if (*a && (*a)->r_v > ((*a)->next)->r_v)
		op_list(a, b, "sa");
	else if (*b && (*b)->r_v < ((*b)->next)->r_v)
		op_list(a, b, "sb");
}*/

static void	move_r(t_list **a, t_list **b, size_t size, size_t range)
{
	size_t	count;
	size_t	limit;
//	int		new_sort_flag;

	count = 0;
	limit = range;
//	new_sort_flag = 0;
	while (*a && (*a) != (*a)->next && size)
	{
		if ((*a)->r_v < limit && (*a)->r_v != size - 1)
		{
			op_list(a, b, "pb");
			count++;
		}
		else if (find_next(a, 0, limit, 1) < find_next(a, 0, limit, 0))
			op_list(a, b, "ra");
		else
			op_list(a, b, "rra");
		// if (count == size / 2 && !new_sort_flag)
		// {
		// 	new_sort(a, b, size);
		// 	new_sort_flag = 1;
		// }
		if (count == limit)
			limit = limit + range;
		//new_sort(a, b);
		//if (*b && (*b)->r_v < ((*b)->next)->r_v)
		//	op_list(a, b, "sb");
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
		else if (find_next(b, limit, size, 1) < (count / 2))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
		if (count <= limit && range > 0 && limit > range)
			limit = limit - range;
		else if (count <= limit)
			limit = limit - 1;
		//if (*a && (*a)->r_v > ((*a)->next)->r_v)
		//	op_list(a, b, "sa");
	}
}

static void	new_sort_2(t_list **a, t_list **b, int reverse)
{
	//size_t	size;
	size_t		target;
	
	//size = count_list(*a) + count_list(*b);
	while (*a && !reverse)
	{
		if (!(*b) || (*b)->next == (*b) || (*a)->r_v > (*b)->r_v || (*a)->r_v == 0)
		{
			op_list(a, b, "pb");
			if (*a)
				target = (*a)->r_v;
		}
		else if (!find_next(b, target, (*a)->r_v, 1))
			target--;
		else if (find_next(b, target, (*a)->r_v, 1) <= find_next(b, target, (*a)->r_v, 0))
			op_list(a, b, "rb");
		else
			op_list(a, b, "rrb");
		if (*a && target > (count_list(*a) + count_list(*b)))
		{
			op_list(a, b, "ra");
			target = (*a)->r_v;
		}
	}
	while (*b && reverse == 1)
	{
		if (!(*a) || (*a)->next == (*a) || (*a)->r_v > (*b)->r_v)
		{
			op_list(a, b, "pa");
			if (*b)
				target = (*b)->r_v;
		}
		else if (!find_next(a, (*b)->r_v, target, 1))
			target++;
		else if (find_next(a, (*b)->r_v, target, 1) <= find_next(a, (*b)->r_v, target, 0))
			op_list(a, b, "ra");
		else
			op_list(a, b, "rra");
		if (*b && target > (count_list(*a) + count_list(*b)))
		{
			op_list(a, b, "rb");
			target = (*b)->r_v;
		}
		//printf("a: %ld -- b: %ld\n", (*a)->r_v, (*b)->r_v);
		//usleep(10000);
	}
}
