/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:30:44 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:30:55 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}				t_node;

char	**ft_split(char *s, char c);
char	*ft_strrev(char *str);
void	push(t_node **head, int val, char c);
void	ft_swap(t_node **stack, char c);
void	move_to_end(t_node **head, char c);
void	move_to_front(t_node **head, char c);
int		pop(t_node **headRef);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
int		smallest(t_node *a, int b);
void	sort_4(t_node **a, t_node **b);
void	sort_4_5(t_node **a, t_node **b, int i);
void	sort_3(t_node **stk, int a, int b, int c);
void	ft_sort(t_node **a, t_node **b, int i);
int		is_sort(t_node *a);
int		smallest(t_node *a, int b);
int		small_index(t_node *a);
long	ft_atoi_long(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
int		stack_size(t_node **stack);
void	print_error(void);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);
void	ss(t_node **a, t_node **b);
int		find_ind(t_node **a, int size, int ind);
void	indexing(t_node **a, int length);
int		bigest(t_node *a, int b);
int		big_index(t_node *a);
void	babo_sort(t_node **a, t_node **b, int size);
void	babo(t_node **a, t_node **b, int size);
#endif
