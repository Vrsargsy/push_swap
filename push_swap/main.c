/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:30:37 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:30:38 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int	is_repeat(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		if (ft_atoi_long(s[i]) > INT_MAX || ft_atoi_long(s[i]) < INT_MIN)
			print_error();
		while (s[j])
		{
			if (ft_atoi_long(s[i]) == ft_atoi_long(s[j]))
				print_error();
			j++;
		}
		i++;
	}
	return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	arg_val(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(is_digit(arg[i])) && !(arg[i] == '-' || arg[i] == '+'
				|| arg[i] == 32))
			print_error();
		if ((arg[i + 1] == '-' && arg[i] == '-') || (arg[i] == '+'
				&& arg[i + 1] == '+'))
			print_error();
		if ((arg[i + 1] == '-' && is_digit(arg[i]))
			|| (is_digit(arg[i]) && arg[i + 1] == '+'))
			print_error();
		if ((arg[i] == '-' && !is_digit(arg[i + 1]))
			|| (!is_digit(arg[i + 1]) && arg[i] == '+'))
			print_error();
		i++;
	}
	return (1);
}

char	*arg_check(char **arg)
{
	int		i;
	char	*str;

	i = 1;
	str = "";
	while (arg[i])
	{
		str = ft_strjoin(str, arg[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**s_av;
	int		i;
	char	*str;

	str = arg_check(av);
	i = 0;
	if (ac < 2 && !arg_val(str))
		print_error();
	s_av = ft_split(str, ' ');
	free(str);
	if (!is_repeat(s_av))
		print_error();
	while (s_av[i] != '\0')
		i++;
	i--;
	while (i >= 0)
		push(&a, ft_atoi_long(s_av[i--]), '0');
	i = 0;
	while (s_av[i] != '\0')
		i++;
	ft_sort(&a, &b, i);
	return (0);
}
