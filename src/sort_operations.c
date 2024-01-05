/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:56:42 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/05 23:25:10 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*op_swap(t_list *list, char op)
{
	t_list	*temp_node;

	if (!list || !list->next)
		return (list);
	else if (op == 'a')
		write(1, "sa\n", 3);
	else if (op == 'b')
		write(1, "sb\n", 3);
	else
		return (list);
	temp_node = list;
	list = list->next;
	(temp_node->prev)->next = list;
	list->prev = temp_node->prev;
	temp_node->next = list->next;
	list->next = temp_node;
	return (list);
}

t_list	*op_rotate(t_list *list, char op)
{
	if (!list || !list->next)
		return (list);
	if (op == 'a')
		write(1, "ra\n", 3);
	else if (op == 'b')
		write(1, "rb\n", 3);
	else
		return (list);
	return (list->next);
}

t_list	*op_push_b(t_list *a, t_list **b)
{
	t_list	*temp_node;
	
	if (!a)
		return (a);
	if (!*b)
	{
		*b = a;
		a = a->next;
		if (a)
			(a->prev)->next = a;
		(*b)->next = NULL;
		(*b)->prev = NULL;
		write(1, "pb\n", 3);
		return (a);
	}
	temp_node = a;
	a = a->next;
	if (a)
	{
		printf("((a->prev)->next)->r_v: %ld\n", ((a->prev)->next)->r_v);
		(a->prev)->next = a;
	}
	if ((*b)->next)
	{
		temp_node->prev = (*b)->prev;
		((*b)->prev)->next = temp_node;
	}
	else
	{
		(*b)->next = temp_node;
		(*b)->prev = temp_node;
	}
	temp_node->next = *b;
	write(1, "pb\n", 3);
	return (a);
}
