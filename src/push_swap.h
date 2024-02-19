/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:07:58 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/16 14:37:30 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				value;
	size_t			r_v;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//init_stack.c
t_list	*init_stack(long *numbers);
//sort_big.c
void	sort_big(t_list **a, t_list **b, size_t size);
//sort_small.c
void	sort_small(t_list **a, t_list **b, size_t size);
//sort_operations.c
void	op_list(t_list **a, t_list **b, char *op);
//ft_split.c
char	**ft_split(char const *s, char c);
//utils_list.c
size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_list(t_list *list);
int		check_sort(t_list *list, char order);
//utils.c
void	*ft_calloc(size_t nmemb, size_t size);
size_t	array_len(char **array);
size_t	str_len(char *str);
long	ft_atoi(char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

#endif
