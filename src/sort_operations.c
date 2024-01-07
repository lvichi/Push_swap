/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:56:42 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/07 00:22:15 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*op_swap(t_list *list, char op)
{
	t_list	*temp_node;

	if (!list || list->next == list)
		return (list);
	else if (op == 'a')
		write(1, "sa\n", 3);
	else if (op == 'b')
		write(1, "sb\n", 3);
	temp_node = list;
	list = list->next;
	if (list->next != temp_node)
	{
		temp_node->next = list->next;
		(list->next)->prev = temp_node;
		list->next = temp_node;
		list->prev = temp_node->prev;
		(temp_node->prev)->next = list;
		temp_node->prev = list;
	}
	return (list);
}

void	op_rotate(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp("ra", op))
		*a = (*a)->next;
	else if (!ft_strcmp("rb", op))
		*b = (*b)->next;
	else if (!ft_strcmp("rra", op))
		*a = (*a)->prev;
	else if (!ft_strcmp("rrb", op))
		*b = (*b)->prev;
	else if (!ft_strcmp("rr", op))
	{
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (!ft_strcmp("rrr", op))
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
	}
	else
		return ;
	write(1, op, str_len(op));
	write(1, "\n", 1);
}

static void	op_push_src(t_list **temp_node, t_list **src, t_list **dest)
{
	*temp_node = *src;
	if ((*src)->next != *src)
		*src = (*src)->next;
	else
		*src = NULL;
	if (*src)
	{
		(*src)->prev = (*temp_node)->prev;
		((*temp_node)->prev)->next = *src;
	}
	if (!*dest)
	{
		*dest = *temp_node;
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
}

void	op_push(t_list **src, t_list **dest, char op)
{
	t_list	*temp_node;

	if (!*src)
		return ;
	op_push_src(&temp_node, src, dest);
	if (*dest != temp_node)
	{
		temp_node->next = *dest;
		if ((*dest)->prev)
		{
			temp_node->prev = (*dest)->prev;
			((*dest)->prev)->next = temp_node;
		}
		else
		{
			temp_node->prev = *dest;
			(*dest)->next = temp_node;
		}
		(*dest)->prev = temp_node;
		*dest = temp_node;
	}
	if (op == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
