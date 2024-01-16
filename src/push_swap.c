/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skinners77 <lvichi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:39:01 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/16 15:46:58 by skinners77       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv);
long			*ft_nbr_split(char *str);
static long		*ft_split_array(int len, char **array);
static int		check_input(int len, char **array);
static t_list	*sort_list(t_list *a);

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
		a = sort_list(a);
		free_list(a);
	}
}

long	*ft_nbr_split(char *str)
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

static t_list	*sort_list(t_list *a)
{
	t_list	*b;
	size_t	size;

	b = NULL;
	size = count_list(a);
	if (size >= 16)
		sort_big(&a, &b, size);
	else
		sort_min(&a, &b, size);
	// print_lists(a, b);
	// if (check_sort(a, 'a'))
	// 	write(1, "\nOK!\n", 5);
	// else
	// 	write(1, "\nKO\n", 4);
	// print_moves();//					delete
	free_list(b);
	return (a);
}
