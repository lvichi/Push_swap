/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:00:11 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 14:37:00 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

ssize_t			ft_get_next_line(int fd, char **str);
static char		*ft_strcat(char *str_first, char *str_second);

ssize_t	ft_get_next_line(int fd, char **str)
{
	char	*buffer;
	ssize_t	ret;

	buffer = (char *)ft_calloc(sizeof(char), 2);
	while (1)
	{
		ret = read(fd, buffer, 1);
		*str = ft_strcat(*str, buffer);
		if (ret <= 0 || buffer[0] == '\n')
			break ;
	}
	free(buffer);
	return (ret);
}

static char	*ft_strcat(char *str_first, char *str_second)
{
	char	*str;
	int		i;
	int		t;

	str = (char *)ft_calloc(sizeof(char),
			str_len(str_first) + str_len(str_second) + 1);
	if (!str)
		return (NULL);
	t = 0;
	i = 0;
	while (str_first && str_first[i])
		str[t++] = str_first[i++];
	i = 0;
	while (str_second && str_second[i])
		str[t++] = str_second[i++];
	str[t] = 0;
	if (str_first)
		free(str_first);
	return (str);
}
