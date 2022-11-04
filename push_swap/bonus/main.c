/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:39:37 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:39:38 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**val(void)
{
	char	*str;
	char	**res;
	int		i;
	int		j;

	i = -1;
	str = get_next_line();
	res = ft_split(str, '\n');
	free(str);
	while (res[++i])
	{
		if (ft_strlen(res[i]) < 2)
			print_error();
		j = -1;
		while (res[i][++j])
		{
			if (res[i][j] == ' ' || (res[i][j] != 'p' && res[i][j] != 's'
				&& res[i][j] != 'r' && res[i][j] != 'a' && res[i][j] != 'b'))
			{
				print_error();
			}
		}
	}
	return (res);
}

void	do_val_2(t_node_b **a, t_node_b **b, char **str, int i)
{
	if (ft_strcmp(str[i], "rra"))
		move_to_front_b(a, '0');
	else if (ft_strcmp(str[i], "rrb"))
		move_to_front_b(b, '0');
	else if (ft_strcmp(str[i], "ss"))
		ss_bonus(a, b);
	else if (ft_strcmp(str[i], "rrr"))
		rrr_bonus(a, b);
	else if (ft_strcmp(str[i], "rr"))
		rr_bonus(a, b);
	else if (ft_strcmp(str[i], "sa"))
		ft_swap_b(a, '0');
	else if (ft_strcmp(str[i], "sb"))
		ft_swap_b(b, '0');
	else if (ft_strcmp(str[i], "rb"))
		move_to_end_b(b, '0');
	else
		print_error();
}

void	do_val(t_node_b **a, t_node_b **b)
{
	char	**str;
	int		i;

	str = val();
	i = -1;
	if (!str || !*str)
		print_error();
	while (str[++i])
	{
		if (ft_strcmp(str[i], "pb"))
			pb_bonus(a, b);
		else if (ft_strcmp(str[i], "pa"))
			pa_bonus(a, b);
		else if (ft_strcmp(str[i], "ra"))
			move_to_end_b(a, '0');
		else
			do_val_2(a, b, str, i);
		free(str[i]);
	}
	free(str);
	if (is_sort(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_node_b	*a;
	t_node_b	*b;
	char		**s_av;
	int			i;
	char		*str;

	str = arg_check(av);
	i = 0;
	if (!arg_val(str) && ac < 2)
		print_error();
	s_av = ft_split(str, ' ');
	free(str);
	if (!is_repeat(s_av))
		print_error();
	while (s_av[i] != '\0')
		i++;
	i--;
	while (i >= 0)
		push_b(&a, ft_atoi_long(s_av[i--]), '0');
	i = 0;
	while (s_av[i] != '\0')
		i++;
	do_val(&a, &b);
	return (0);
}
