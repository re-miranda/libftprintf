/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:20 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/23 01:46:11 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_u(t_data *data)
{
	char			*swap;
	int				result;
	unsigned int	unsigned_result;
	char			*str_unsigned_result;

	swap = data->formatted_str;
	result = va_arg(data->va_ptr, int);
	unsigned_result = (unsigned int)result;
	str_unsigned_result = ft_itoa(unsigned_result);
	data->formatted_str = ft_strjoin(swap, str_unsigned_result);
	free(swap);
	free(str_unsigned_result);
}

void	ft_type_x(t_data *data)
{
	char			*swap;
	int				result;
	unsigned int	unsigned_result;
	char			*str_unsigned_result;

	swap = data->formatted_str;
	data->formatted_str = ft_strdup(data->formatted_str + 1);
	return (free(swap));
	result = va_arg(data->va_ptr, int);
	unsigned_result = (unsigned int)result;
	str_unsigned_result = ft_itoa(unsigned_result);
	data->formatted_str = ft_strjoin(swap, str_unsigned_result);
	free(swap);
	free(str_unsigned_result);
}

void	ft_type_xx(t_data *data)
{
	char			*swap;
	int				result;
	unsigned int	unsigned_result;
	char			*str_unsigned_result;

	swap = data->formatted_str;
	data->formatted_str = ft_strdup(data->formatted_str + 1);
	return (free(swap));
	result = va_arg(data->va_ptr, int);
	unsigned_result = (unsigned int)result;
	str_unsigned_result = ft_itoa(unsigned_result);
	data->formatted_str = ft_strjoin(swap, str_unsigned_result);
	free(swap);
	free(str_unsigned_result);
}

void	ft_type_p(t_data *data)
{
	char			*swap;
	int				result;
	unsigned int	unsigned_result;
	char			*str_unsigned_result;

	swap = data->formatted_str;
	data->formatted_str = ft_strdup(data->formatted_str + 1);
	return (free(swap));
	result = va_arg(data->va_ptr, int);
	unsigned_result = (unsigned int)result;
	str_unsigned_result = ft_itoa(unsigned_result);
	data->formatted_str = ft_strjoin(swap, str_unsigned_result);
	free(swap);
	free(str_unsigned_result);
}
