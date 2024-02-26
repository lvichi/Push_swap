/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:17 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 16:51:59 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_lists(t_list *a, t_list *b, long *numbers, char **moves_list);
int		check_sort(t_list *list, size_t	size);
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

void	free_lists(t_list *a, t_list *b, long *numbers, char **moves_list)
{
	size_t	i;
	size_t	size;
	t_list	*temp_list;

	size = count_list(a);
	while (a && size--)
	{
		temp_list = a;
		a = a->next;
		free(temp_list);
	}
	size = count_list(b);
	while (b && size--)
	{
		temp_list = b;
		b = b->next;
		free(temp_list);
	}
	i = -1;
	while (moves_list && moves_list[++i])
		free(moves_list[i]);
	if (moves_list)
		free(moves_list);
	if (numbers)
		free(numbers);
}

int	check_sort(t_list *list, size_t	size)
{
	size_t	i;
	size_t	prev_num;

	if (!list || count_list(list) != size)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	prev_num = list->r_v;
	i = 0;
	while (i++ < size - 1)
	{
		list = list->next;
		if (prev_num > list->r_v)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		prev_num = list->r_v;
	}
	write(1, "OK\n", 3);
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
