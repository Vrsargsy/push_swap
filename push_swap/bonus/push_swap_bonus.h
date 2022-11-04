/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:39:18 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:39:20 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct node_b
{
	int				data;
	int				index;
	struct node_b	*next;
}					t_node_b;

char	*get_next_line(void);
void	pb_bonus(t_node_b **a, t_node_b **b);
void	pa_bonus(t_node_b **a, t_node_b **b);
void	push_b(t_node_b **head, int val, char c);
void	ft_swap_b(t_node_b **stack, char c);
void	move_to_end_b(t_node_b **head, char c);
void	move_to_front_b(t_node_b **head, char c);
void	rr_bonus(t_node_b **a, t_node_b **b);
void	rrr_bonus(t_node_b **a, t_node_b **b);
void	ss_bonus(t_node_b **a, t_node_b **b);
int		pop_bonus(t_node_b **headRef);
int		ft_strcmp(char *s1, char *s2);
char	**val(void);
void	do_val_2(t_node_b **a, t_node_b **b, char **str, int i);
void	do_val(t_node_b **a, t_node_b **b);
char	**ft_split(char *s, char c);
int		is_repeat(char **s);
int		is_digit(char c);
int		arg_val(char *arg);
char	*arg_check(char **arg);
void	print_error(void);
int		is_sort(t_node_b *a);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
long	ft_atoi_long(const char *str);

#endif
