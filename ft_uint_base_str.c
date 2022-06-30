/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_base_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:08:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/30 22:05:59 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nbrlen(unsigned int n, int base_count)
{
	if (n >= (unsigned int)base_count)
		return (1 + ft_nbrlen(n / base_count, base_count));
	return (1);
}

static int	base_test(char *base, int i, int base_count)
{
	if (base[i] == '-' || base[i] == '+')
		return (1);
	if (base[i] < 32 || base[i] > 126)
		return (1);
	if (i < base_count && base[i] == base[base_count])
		return (1);
	return (0);
}

static void	recursive_write(unsigned int nbr, char *base, int base_count, char *str, int str_len)
{
	// char	n;

	// n = base[nbr % base_count];
	// if (nbr < (unsigned int)base_count)
	// {
	// 	write(1, &n, 1);
	// }
	// else
	// {
	// 	recursive_write(nbr / base_count, base, base_count, str, );
	// 	write(1, &n, 1);
	// }
	str[str_len] = base[nbr % base_count];
	if (nbr > (unsigned int)base_count)
		recursive_write(nbr / base_count, base, base_count, str, --str_len);
}

char	*ft_uint_base_str(unsigned int nbr, char *base)
{
	int		base_count;
	int		i;
	char	*str;
	int		str_len;

	base_count = 0;
	while (base[base_count])
	{
		i = 0;
		while (i <= base_count)
		{
			if (base_test(base, i, base_count))
				return (NULL);
			i++;
		}
		base_count++;
	}
	if (base_count < 2)
		return (NULL);
	str_len = ft_nbrlen(nbr, base_count);
	str = calloc(str_len + 1, sizeof(char));
	recursive_write(nbr, base, base_count, str, --str_len);
	return (str);
}
