/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:39:01 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/05 17:35:43 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(int len, char **array)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		if (array[i][0] == '-' || array[i][0] == '+')
			j++;
		while (array[i][++j])
			if (array[i][j] < '0' || array[i][j] > '9')
				return (0);
		if (j > 11)
			return (0);
	}
	return (1);
}

static int	check_duplicate(long n, long *numbers)
{
	ssize_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (++i <= numbers[0])
		if (numbers[i] == n)
			count++;
	if (count != 1)
		return (1);
	return (0);
}

static long	*ft_split_array(int len, char **array)
{
	long	*numbers;
	ssize_t	i;

	if (!check_input(len, array))
		return (NULL);
	numbers = (long *)ft_calloc(sizeof(long), len + 1);
	if (!numbers)
		return (NULL);
	numbers[0] = len;
	i = -1;
	while (array[++i])
		numbers[i + 1] = ft_atoi(array[i]);
	i = 0;
	while (++i <= numbers[0])
	{
		if (numbers[i] > INT_MAX || numbers[i] < INT_MIN
			|| check_duplicate(numbers[i], numbers))
		{
			free(numbers);
			return (NULL);
		}
	}
	return (numbers);
}

static long	*ft_nbr_split(char *str)
{
	long	*numbers;
	ssize_t	i;
	char	**array;

	array = ft_split(str, ' ');
	if (!array)
		return (NULL);
	numbers = ft_split_array(array_len(array), array);
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (numbers);
}

int	main(int argc, char **argv)
{
	long	*numbers;
	t_list	*a;

	a = NULL;
	if (argc < 2)
		exit (0);
	else if (argc == 2)
		numbers = ft_nbr_split(argv[1]);
	else
		numbers = ft_split_array(argc - 1, &argv[1]);
	if (!numbers)
		write(1, "Error\n", 6);
	else
		a = init_stack(numbers);
	if (a)
	{
		print_list(a);
		a = sort_list(a);
		write(1, "\n", 1);
		print_list(a);
		free_list(a);
	}
}
