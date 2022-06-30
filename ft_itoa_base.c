/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:14:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/25 03:05:25 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
		return (1 + ft_nbrlen(n / 10));
	return (1);
}

static void	intstr(char *str, size_t str_i, int n)
{
	str[str_i] = (n % 10) + '0';
	if (n >= 10)
		intstr(str, --str_i, n / 10);
}

char	*ft_itoa(int n, char *base)
{
	char	*str;
	size_t	str_size;
	int	base_count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str_size = ft_nbrlen(n) + 1;
	if (n < 0)
		str_size++;
	str = malloc(sizeof(char) * str_size);
	if (str == NULL)
		return (NULL);
	str[--str_size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	intstr(str, --str_size, n);
	return (str);
}
