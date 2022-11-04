/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:30:19 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:30:21 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigest(t_node *a, int b)
{
	while (a != NULL )
	{
		if (b < a ->index)
			return (0);
		a = a ->next;
	}
	return (1);
}

int	big_index(t_node *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		if (bigest(a, a ->index))
			break ;
		a = a ->next;
		i++;
	}
	return (i);
}

int	is_down(t_node **a, int size, int max)
{
	t_node	*b;
	int		i;

	indexing(a, stack_size(a));
	b = *a;
	i = 0;
	while (b && b ->index != max)
	{
		b = b -> next;
		i++;
	}
	if (i >= size / 2)
		return (1);
	else
		return (0);
}

void	babo_sort(t_node **a, t_node **b, int size)
{
	int	max;
	int	size_b;
	int	is_up;

	indexing(b, size);
	size_b = size;
	while (b && (*b) && size_b)
	{
		max = size_b - 1;
		is_up = big_index(*b);
		while ((*b)-> index != max)
		{
			if (is_up <= size_b / 2)
				move_to_end(b, 'b');
			else
				move_to_front(b, 'b');
		}
		pa(a, b);
		size_b--;
	}
}

void	babo(t_node **a, t_node **b, int size)
{
	int	count;
	int	x;

	indexing(a, stack_size(a));
	count = 0;
	if (size > 100)
		x = 30;
	else
		x = 15;
	while (count < size)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			move_to_end(b, 'b');
			count++;
		}
		else if ((*a)-> index <= count + x)
		{
			pb(a, b);
			count++;
		}
		else
			move_to_end(a, 'a');
	}
}
