/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:17 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/06 20:28:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	t_list	*first;

	if (list)
		first = list;
	else
		return ;
	printf("value: %d\tr_v: %ld\t", list->value, list->r_v);
	if (list->next)
		printf("next: %ld\tprev: %ld\n", (list->next)->r_v, (list->prev)->r_v);
	else
		printf("\n");
	list = list->next;
	while (list && list != first)
	{
		printf("value: %d\tr_v: %ld\t", list->value, list->r_v);
		if (list->next)
			printf("next: %ld\tprev: %ld\n", (list->next)->r_v,
				(list->prev)->r_v);
		else
			printf("\n");
		usleep(100000);
		list = list->next;
	}
}

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
