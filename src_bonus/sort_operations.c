/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:56:42 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 14:39:22 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		op_list(t_list **a, t_list **b, char *op);
static void	op_swap(t_list **list);
static void	op_rotate(t_list **a, t_list **b, char *op);
static void	op_push(t_list **src, t_list **dest);

void	op_list(t_list **a, t_list **b, char *op)
{
	if ((!ft_strcmp("sa\n", op) || !ft_strcmp("ss\n", op)) && *a)
		op_swap(a);
	if ((!ft_strcmp("sb\n", op) || !ft_strcmp("ss\n", op)) && *b)
		op_swap(b);
	if ((!ft_strcmp("ra\n", op) || !ft_strcmp("rra\n", op)) && *a)
		op_rotate(a, b, op);
	if ((!ft_strcmp("rb\n", op) || !ft_strcmp("rrb\n", op)) && *b)
		op_rotate(a, b, op);
	if ((!ft_strcmp("rr\n", op) || !ft_strcmp("rrr\n", op)) && *a && *b)
		op_rotate(a, b, op);
	if (!ft_strcmp("pa\n", op) && *b)
		op_push(b, a);
	if (!ft_strcmp("pb\n", op) && *a)
		op_push(a, b);
}

static void	op_swap(t_list **list)
{
	t_list	*temp_node;

	if ((*list)->next == *list)
		return ;
	temp_node = *list;
	*list = (*list)->next;
	if ((*list)->next != temp_node)
	{
		temp_node->next = (*list)->next;
		((*list)->next)->prev = temp_node;
		(*list)->next = temp_node;
		(*list)->prev = temp_node->prev;
		(temp_node->prev)->next = *list;
		temp_node->prev = *list;
	}
}

static void	op_rotate(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp("ra\n", op))
		*a = (*a)->next;
	else if (!ft_strcmp("rb\n", op))
		*b = (*b)->next;
	else if (!ft_strcmp("rra\n", op))
		*a = (*a)->prev;
	else if (!ft_strcmp("rrb\n", op))
		*b = (*b)->prev;
	else if (!ft_strcmp("rr\n", op))
	{
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (!ft_strcmp("rrr\n", op))
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
	}
	else
		return ;
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

static void	op_push(t_list **src, t_list **dest)
{
	t_list	*temp_node;

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
}
