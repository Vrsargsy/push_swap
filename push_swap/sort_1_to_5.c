/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:31:17 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:31:19 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_node **a, t_node **b)
{
	int	i;

	i = small_index(*a);
	if (is_sort(*a))
		return ;
	if (i == 1)
		move_to_end(a, 'a');
	if (i == 2)
	{
		move_to_front(a, 'a');
		move_to_front(a, 'a');
	}
	if (i == 3)
		move_to_front(a, 'a');
	pb(a, b);
	sort_3(a, (*a)-> data, (*a)-> next-> data, (*a)-> next -> next -> data);
	pa(a, b);
}

void	sort_5_h(t_node **a, t_node **b)
{
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	sort_4_5(t_node **a, t_node **b, int i)
{
	int	c;

	c = small_index(*a);
	if (i == 4)
		sort_4(a, b);
	if (i == 5)
	{
		if (is_sort(*a))
			return ;
		if (c == 1)
			move_to_end(a, 'a');
		if (c == 2)
		{
			move_to_end(a, 'a');
			move_to_end(a, 'a');
		}
		if (c == 3)
		{
			move_to_front(a, 'a');
			move_to_front(a, 'a');
		}
		if (c == 4)
			move_to_front(a, 'a');
		sort_5_h(a, b);
	}
}

void	sort_3(t_node **stk, int a, int b, int c)
{
	if ((a < b && b > c) && a < c)
	{
		ft_swap(stk, 'a');
		move_to_end(stk, 'a');
	}
	else if ((a < b && b > c) && a > c)
		move_to_front(stk, 'a');
	else if ((a > b && a > c) && (b < c))
		move_to_end(stk, 'a');
	else if (a > b && b < c)
		ft_swap(stk, 'a');
	else if (a > b && b > c)
	{
		ft_swap(stk, 'a');
		move_to_front(stk, 'a');
	}
}

void	ft_sort(t_node **a, t_node **b, int i)
{
	if (i == 2 && (*a)->next ->data < (*a)->data)
		ft_swap(a, 'a');
	if (i == 3)
		sort_3(a, (*a)->data, (*a)-> next ->data, (*a)->next ->next ->data);
	if (i > 3 && i <= 5)
	{
		sort_4_5(a, b, i);
	}
	if (i > 5)
	{
		if (is_sort(*a))
			return ;
		babo(a, b, stack_size(a));
		babo_sort(a, b, i);
	}
}
