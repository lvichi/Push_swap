/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:39:01 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/29 15:51:57 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv);
static long		*ft_nbr_split(char *str);
static long		*ft_split_array(int len, char **array);
static int		check_input(int len, char **array);
static void		sort(t_list **a, t_list **b);

int	main(int argc, char **argv)
{
	long	*numbers;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit (0);
	else if (argc == 2)
		numbers = ft_nbr_split(argv[1]);
	else
		numbers = ft_split_array(argc - 1, &argv[1]);
	if (!numbers)
		write(2, "Error\n", 6);
	else
		a = init_stack(numbers);
	if (!a)
		return (0);
	if (!check_sort(a, 'a'))
		sort(&a, &b);
	free_list(a);
	free_list(b);
}

long	*ft_nbr_split(char *str)
{
	long	*numbers;
	ssize_t	i;
	char	**array;

	array = ft_split(str, ' ');
	if (!array)
		return (NULL);
	if (!array_len(array))
	{
		free(array);
		return (NULL);
	}
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
		if ((array[i][0] == '-' || array[i][0] == '+') && array[i][1])
			j++;
		while (array[i][++j])
			if (array[i][j] < '0' || array[i][j] > '9')
				return (0);
		if (j > 11)
			return (0);
	}
	return (1);
}

static void	sort(t_list **a, t_list **b)
{
	size_t	size;

	size = count_list(*a);
	while (*a && size > 5)
	{
		op_list(a, b, "pb");
		if ((*b)->r_v <= (size / 2))
			op_list(a, b, "rb");
	}
	while (count_list(*a) > 3)
		op_list(a, b, "pb");
	if (*a)
		sort_three(a, 'a');
	else
		op_list(a, b, "pa");
	while (*b)
		transfer_cheap(a, b, (int)count_list(*a), (int)count_list(*b));
	while (find_next(*a, (int)size, -1, 0) > 0)
		op_list(a, b, "ra");
	while (find_next(*a, (int)size, -1, 0) < 0)
		op_list(a, b, "rra");
}
