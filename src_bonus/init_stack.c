/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:24:03 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 16:41:31 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list			*init_stack(long *numbers);
static t_list	*relative_value(int index, long *numbers, t_list *node);
static t_list	*new_node(int index, long *numbers, t_list *list);

t_list	*init_stack(long *numbers)
{
	t_list	*a;
	t_list	*first;
	int		i;

	a = NULL;
	a = new_node(1, numbers, a);
	first = a;
	i = 1;
	while (++i <= numbers[0])
		a = new_node(i, numbers, a);
	a->next = first;
	first->prev = a;
	a = first;
	return (a);
}

static t_list	*relative_value(int index, long *numbers, t_list *node)
{
	size_t	relative_value;
	int		i;

	relative_value = 0;
	i = 0;
	while (++i <= numbers[0])
		if (numbers[i] < numbers[index])
			relative_value++;
	node->r_v = relative_value;
	node->transfer_cost_a = 0;
	node->transfer_cost_b = 0;
	return (node);
}

static t_list	*new_node(int index, long *numbers, t_list *list)
{
	t_list	*node;

	node = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!node)
		return (NULL);
	node->value = numbers[index];
	node = relative_value(index, numbers, node);
	if (list == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		return (node);
	}
	node->prev = list;
	list->next = node;
	return (node);
}
