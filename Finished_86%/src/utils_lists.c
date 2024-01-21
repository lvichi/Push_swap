/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skinners77 <lvichi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:17 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/16 14:59:33 by skinners77       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_list(t_list *list);
int		check_sort(t_list *list, char order);

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
