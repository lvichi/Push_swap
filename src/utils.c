/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:22:18 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/30 20:38:54 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	size = nmemb * size;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	while (size)
		((char *)ret)[--size] = 0;
	return (ret);
}

size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
