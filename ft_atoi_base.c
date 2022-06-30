/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 06:34:18 by rmiranda          #+#    #+#             */
/*   Updated: 2022/02/18 19:32:37 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	where_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != str)
		i++;
	return (i);
}

static int	is_in_base(char str, char *base)
{
	while (*base)
	{
		if (str == *base)
		{
			return (1);
		}
		base++;
	}
	return (0);
}

static int	base_test_and_count(char *base)
{
	int	j;
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft2_atoi(char *str, char *base, int base_count)
{
	int	sign;
	int	output;
	int	i;

	sign = 1;
	output = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (is_in_base(str[i], base))
	{
		output = ((output * base_count) + where_in_base(str[i], base));
		i++;
	}
	return (output * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	base_count;

	base_count = base_test_and_count(base);
	if (base_count < 2)
		return (0);
	n = ft2_atoi(str, base, base_count);
	return (n);
}
