/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:30:12 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:30:13 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	a;
	int		b;

	a = 0;
	b = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			b *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	return (a * b);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest || s2 == 0)
		return (0);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	if (*s1)
		free(s1);
	dest[j] = 0;
	return (dest);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	stack_size(t_node **stack)
{
	t_node	*node;
	int		i;

	i = 0;
	if (stack)
	{
		node = *stack;
		while (node)
		{
			i++;
			node = node->next;
		}
	}
	return (i);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
