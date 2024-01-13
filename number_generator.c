/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skinners77 <lvichi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:39:45 by skinners77        #+#    #+#             */
/*   Updated: 2024/01/13 19:32:33 by skinners77       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <sodium.h>

long	ft_atoi(char *nptr);
void	number_gen(long number);
void	ft_putnbr(long nbr);

int	main(int argc, char **argv)
{
	if (argc == 2)
		number_gen(ft_atoi(argv[1]));
}

void	number_gen(long number)
{
	int i;
	long int temp;

	i = -1;
	if (sodium_init() < 0)
	{
		write(1, "sodium_lib error.\n", 18);
		return ;
	}
	while (++i < number)
	{
		temp = randombytes_random();
		temp = temp - INT_MAX - 1;
		ft_putnbr(temp);
		if (i < number -1)
			write(1, " ", 1);
	}
}

long	ft_atoi(char *nptr)
{
	size_t	n;
	int		i;
	int		negative;

	n = 0;
	i = 0;
	negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			n = (n * 10) + (nptr[i] - 48);
		else
			break ;
		i++;
	}
	return (n * negative);
}

void	ft_putnbr(long nbr)
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
