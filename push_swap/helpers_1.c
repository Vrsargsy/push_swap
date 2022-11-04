/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:31:02 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:31:04 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **a, t_node **b)
{
	move_to_end(a, '0');
	move_to_end(b, '0');
	write(1, "rr", 2);
}

void	rrr(t_node **a, t_node **b)
{
	move_to_front(a, '0');
	move_to_front(b, '0');
	write(1, "rrr", 3);
}

void	ss(t_node **a, t_node **b)
{
	ft_swap(a, '0');
	ft_swap(b, '0');
	write(1, "ss", 2);
}
