/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:08:23 by lvichi            #+#    #+#             */
/*   Updated: 2024/02/26 16:59:45 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //delete

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				value;
	size_t			r_v;
	int				transfer_cost_a;
	int				transfer_cost_b;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//init_stack.c
t_list	*init_stack(long *numbers);
//moves.c
int		get_moves_list(char ***moves_list);
//sort_operations.c
void	op_list(t_list **a, t_list **b, char *op);
//ft_split.c
char	**ft_split(char const *s, char c);
//ft_get_next_line.c
ssize_t	ft_get_next_line(int fd, char **str);
//utils_list.c
size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_lists(t_list *a, t_list *b, long *numbers, char **moves_list);
int		check_sort(t_list *list, size_t	size);
int		find_next(t_list *list, int size, int min, int max);
//utils.c
void	*ft_calloc(size_t nmemb, size_t size);
size_t	array_len(char **array);
size_t	str_len(char *str);
long	ft_atoi(char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

#endif