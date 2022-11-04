/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:39:32 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/11/01 13:39:33 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(void)
{
	int		rd;
	int		i;
	char	c;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 100000);
	rd = read(0, &c, 1);
	while (rd > 0)
	{
		buffer[i++] = c;
		rd = read(0, &c, 1);
	}
	if (rd == -1 || (rd == 0 && !buffer[i - 1]))
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

int	is_sort(t_node_b *a)
{
	while (a != NULL)
	{
		if (a-> next == NULL)
			return (1);
		if (a->data > a->next ->data)
			return (0);
		a = a->next;
	}
	return (1);
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
