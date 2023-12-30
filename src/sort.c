/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:24:03 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/30 21:44:50 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(long *numbers)
{
	ssize_t	i;

	i = 0;
	while (++i <= numbers[0])
		printf("%ld\n", numbers[i]);
	free(numbers);
}
