/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:23:36 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/08 20:50:08 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putnbr(long nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	c = nbr + '0';
	write(1, &c, 1);
}

static void	print_nodes(t_list *a, t_list *b)
{
	if (a)
	{
		ft_putnbr(a->value);
		write(1, "\tr_v: ", 7);
		ft_putnbr(a->r_v);
		write(1, "\t\t->", 4);
		ft_putnbr((a->next)->r_v);
		write(1, "\t<-", 4);
		ft_putnbr((a->prev)->r_v);
		write(1, "\t\t", 2);
	}
	else
		write(1, "\t\t\t\t\t\t", 6);
	if (b)
		print_nodes(b, NULL);
	else
		write(1, "\n", 1);
}

void	print_lists(t_list *a, t_list *b)
{
	size_t	i;
	t_list	*first_a;
	t_list	*first_b;

	first_a = a;
	first_b = b;
	write(1, "STACK A:\t\t\t\t\tSTACK B:\n", 23);
	i = count_list(a);
	if (count_list(b) > i)
		i = count_list(b);
	while (i-- > 0)
	{
		print_nodes(a, b);
		if (a && a->next != a && a->next != first_a)
			a = a->next;
		else
			a = NULL;
		if (b && b->next != b && b->next != first_b)
			b = b->next;
		else
			b = NULL;
		usleep(100000);
	}
}
