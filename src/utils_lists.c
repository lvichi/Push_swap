/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:17 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/29 15:50:18 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_list(t_list *list);
int		check_sort(t_list *list, char order);
int		find_next(t_list *list, int size, int min, int max);

size_t	count_list(t_list *list)
{
	t_list	*first;
	size_t	size;

	if (list)
		first = list;
	else
		return (0);
	size = 1;
	list = list->next;
	while (list && list != first)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	check_duplicate(long n, long *numbers)
{
	ssize_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (++i <= numbers[0])
		if (numbers[i] == n)
			count++;
	if (count != 1)
		return (1);
	return (0);
}

void	free_list(t_list *list)
{
	size_t	i;
	size_t	size;
	t_list	*temp_list;

	i = 0;
	size = count_list(list);
	while (list && i++ < size)
	{
		temp_list = list;
		list = list->next;
		free(temp_list);
	}
}

int	check_sort(t_list *list, char order)
{
	size_t	i;
	size_t	size;
	size_t	prev_num;

	if (!list || !(order == 'a' || order == 'd'))
		return (0);
	size = count_list(list);
	if (size == 1)
		return (1);
	prev_num = list->r_v;
	i = 0;
	while (i++ < size - 1)
	{
		list = list->next;
		if (order == 'a' && prev_num > list->r_v)
			return (0);
		else if (order == 'd' && prev_num < list->r_v)
			return (0);
		prev_num = list->r_v;
	}
	return (1);
}

int	find_next(t_list *list, int size, int min, int max)
{
	int		i;
	int		size_list;

	size_list = (int)count_list(list);
	i = -1;
	while (++i < size_list && size)
	{
		if (((int)(list->prev)->r_v == min && (int)list->r_v == max)
			|| (min == -1 && (int)list->r_v == max)
			|| (max == size && (int)(list->prev)->r_v == min))
			break ;
		list = list->next;
	}
	if (i > (size_list / 2))
		i = i - size_list;
	return (i);
}
