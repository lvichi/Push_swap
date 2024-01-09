/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:56:42 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/08 21:05:07 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves = 0;

static void	op_swap(t_list **list, char *op);
static void	op_rotate(t_list **a, t_list **b, char *op);
static void	op_push(t_list **src, t_list **dest, char *op);

void	op_list(t_list **a, t_list **b, char *op)
{
	if ((!ft_strcmp("sa", op) || !ft_strcmp("ss", op)) && *a)
		op_swap(a, op);
	if ((!ft_strcmp("sb", op) || !ft_strcmp("ss", op)) && *b)
		op_swap(b, op);
	if (!ft_strcmp("ss", op))
	{
		write(1, op, 2);
		write(1, "\n", 1);
		moves++;//				DELETE
	}
	if ((!ft_strcmp("ra", op) || !ft_strcmp("rra", op)) && *a)
		op_rotate(a, b, op);
	if ((!ft_strcmp("rb", op) || !ft_strcmp("rrb", op)) && *b)
		op_rotate(a, b, op);
	if ((!ft_strcmp("rr", op) || !ft_strcmp("rrr", op)) && *a && *b)
		op_rotate(a, b, op);
	if (!ft_strcmp("pa", op) && *b)
		op_push(b, a, op);
	if (!ft_strcmp("pb", op) && *a)
		op_push(a, b, op);
}

static void	op_swap(t_list **list, char *op)
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
	if (!ft_strcmp("sa", op) || !ft_strcmp("sb", op))
	{
		write(1, op, 2);
		write(1, "\n", 1);
		moves++;//				DELETE
	}
}

static void	op_rotate(t_list **a, t_list **b, char *op)
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
	moves++;//				DELETE
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

static void	op_push(t_list **src, t_list **dest, char *op)
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
	write(1, op, 2);
	write(1, "\n", 1);
	moves++;//				DELETE
}

void	print_moves(void)//				DELETE
{
	printf("moves: %d", moves);
}
