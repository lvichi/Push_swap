/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:17 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/04 16:36:14 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	size_t	i;

	i = 0;
	while (i++ < list->size)
	{
		printf("value: %d relative_value: %ld size: %ld\n", list->value,
			list->relative_value, list->size);
		list = list->next;
	}
}

void	free_list(t_list *list)
{
	size_t	i;
	size_t	size;
	t_list	*temp_list;

	i = 0;
	size = list->size;
	while (i++ < size)
	{
		temp_list = list;
		list = list->next;
		free(temp_list);
	}
}
