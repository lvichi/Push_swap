/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:02:23 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/05 23:21:21 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_list(t_list *a)
{
	t_list	*b;
	size_t	size;
	size_t	half;
	//size_t	pb_count;

	b = NULL;
	size = count_list(a);
	if (size % 2 == 0)
		half = size / 2;
	else
		half = (size/ 2) + 1;
	printf("half: %lu\n", half); //delete
	printf("size: %lu\n", size); //delete
	//pb_count = 0;
	/*while (pb_count < half)
	{
		if (a && a->next && a->r_v > (a->next)->r_v && a->r_v != size - 1)
			a = op_swap(a, 'a'); //need to be created
		if (b && b->next && b->r_v < (b->next)->r_v && b->r_v != half - 1)
			op_swap(b, 'b'); //need to be created
		if (a->r_v < half)
		{
			op_push(a, b, 'b'); //need to be created
			pb_count++;
		}
		else
			op_rotate(a, b, 'a');  //need to be created
		printf("pb_count: %lu/n", pb_count); //delete
	}*/
	a = op_swap(a, 'a');
	//print_list(a);
	printf("\n");
	
	a = op_rotate(a, 'a');
	//print_list(a);
	printf("\n");

	a = op_push_b(a, &b);
	print_list(a);
	printf("\n");
	print_list(b);
	printf("\n");

	a = op_push_b(a, &b);
	sleep(3);
	print_list(b);
	printf("\n");
	sleep(3);
	print_list(a);
	printf("\n");
	
	free_list(b);
	return (a);
}
