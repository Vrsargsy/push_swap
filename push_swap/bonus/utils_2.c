/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:39:27 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:39:28 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

void	push_b(t_node_b **head, int val, char c)
{
	t_node_b	*new_node;

	new_node = (t_node_b *) malloc(sizeof(t_node_b));
	new_node -> data = val;
	new_node -> index = -1;
	new_node -> next = *head;
	*head = new_node;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_swap_b(t_node_b **stack, char c)
{
	int	tmp;

	if (stack)
	{
		tmp = (*stack)-> data;
		(*stack)-> data = (*stack)-> next -> data;
		(*stack)-> next ->data = tmp;
		if (c == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	return ;
}

void	move_to_end_b(t_node_b **head, char c)
{
	t_node_b	*first;
	t_node_b	*last;

	if (*head == NULL || (*head)-> next == NULL)
		return ;
	first = *head;
	last = *head;
	while (last ->next != NULL)
		last = last ->next;
	*head = first ->next;
	first -> next = NULL;
	last -> next = first;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	move_to_front_b(t_node_b **head, char c)
{
	t_node_b	*last;
	t_node_b	*changed_last;

	if (*head == NULL || (*head)-> next == NULL)
		return ;
	last = *head;
	changed_last = NULL;
	while (last -> next != NULL)
	{
		changed_last = last;
		last = last-> next;
	}
	changed_last -> next = NULL;
	last -> next = *head;
	*head = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

int	pop_bonus(t_node_b **headRef)
{
	t_node_b	*head;
	int			result;

	if (*headRef == NULL)
		return (-1);
	head = *headRef;
	result = head ->data;
	(*headRef) = (*headRef)->next;
	free(head);
	return (result);
}
