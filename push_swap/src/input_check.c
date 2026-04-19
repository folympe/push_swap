/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:21:33 by olfhal            #+#    #+#             */
/*   Updated: 2026/04/10 12:21:35 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *av)
{
	int	i;

	if (!av || av[0] == '\0')
		return (0);
	i = 0;
	if (is_sign(av[i]))
	{
		if (av[i + 1] == '\0')
			return (0);
		i++;
	}
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] == '0')
		i++;
	return (av[i] == '\0');
}

static long	ft_atol_safe(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	have_duplicates(char **av)
{
	int		i;
	int		j;
	long	nb1;
	long	nb2;

	i = 1;
	while (av[i])
	{
		nb1 = ft_atol_safe(av[i]);
		j = i + 1;
		while (av[j])
		{
			nb2 = ft_atol_safe(av[j]);
			if (nb1 == nb2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	if (!av || !av[1])
		return (0);
	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
