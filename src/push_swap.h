/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:07:58 by lvichi            #+#    #+#             */
/*   Updated: 2024/01/11 17:07:56 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//                            DELETE
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

t_list	*init_stack(long *numbers);
t_list	*sort_list(t_list *a);
void	op_list(t_list **a, t_list **b, char *op);
void	print_moves(void);//				    			DELETE
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	count_list(t_list *list);
void	free_list(t_list *list);
int		check_sort(t_list *list, char order);
size_t	array_len(char **array);
size_t	str_len(char *str);
long	ft_atoi(char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	print_lists(t_list *a, t_list *b);//             DELETE
void	ft_putnbr(long nbr);//							DELETE and put static

#endif