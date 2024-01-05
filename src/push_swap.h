/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:07:58 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/05 17:26:58 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //delete
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				value;
	size_t			relative_value;
	size_t			size;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*first;
}	t_list;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	array_len(char **array);
size_t	str_len(char *str);
long	ft_atoi(char *nptr);
t_list	*init_stack(long *numbers);
t_list	*sort_list(t_list *a);
void	print_list(t_list *list);
void	free_list(t_list *list);

#endif