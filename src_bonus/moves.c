/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:58:20 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 17:00:29 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			get_moves_list(char ***moves_list);
static char	**add_move(char **old_list, char *str);

int	get_moves_list(char ***moves_list)
{
	char	*str;
	ssize_t	ret;

	ret = 0;
	while (1)
	{
		str = (char *)ft_calloc(sizeof(char), 2);
		ret = ft_get_next_line(0, &str);
		if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n")
			|| !ft_strcmp(str, "ss\n") || !ft_strcmp(str, "ra\n")
			|| !ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rr\n")
			|| !ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rra\n")
			|| !ft_strcmp(str, "rrr\n") || !ft_strcmp(str, "ra\n")
			|| !ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n"))
			*moves_list = add_move(*moves_list, str);
		else if (ret == 0 && !str[0])
			break ;
		else
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

static char	**add_move(char **old_list, char *str)
{
	char	**moves_list;
	size_t	size;
	int		i;

	if (!str)
		return (old_list);
	size = array_len(old_list);
	moves_list = (char **)ft_calloc(sizeof(char **), size + 2);
	i = 0;
	while (old_list && old_list[i])
	{
		moves_list[i] = old_list[i];
		i++;
	}
	moves_list[i] = str;
	if (old_list)
		free(old_list);
	return (moves_list);
}
