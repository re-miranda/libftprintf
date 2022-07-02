/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:37:07 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/30 23:57:58 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_c(t_data *data)
{
	char	*result;

	result = ft_strdup("0");
	result[0] = va_arg(data->va_ptr, int);
	data->total_bytes_write++;
	return (result);
}

char	*ft_type_s(t_data *data)
{
	char	*result;

	result = va_arg(data->va_ptr, char *);
	if (result == NULL)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(result);
	data->total_bytes_write += ft_strlen(result);
	return (result);
}

char	*ft_type_d_i(t_data *data)
{
	int		result;
	char	*str_result;

	result = va_arg(data->va_ptr, int);
	if (ft_strchr(data->found_flags, '+') && result >= 0)
	{
		ft_append_char_to_str('+', &data->formatted_str);
		*ft_strchr(data->found_flags, '+') = 0;
	}
	else if (ft_strchr(data->found_flags, ' ') && result >= 0)
	{
		ft_append_char_to_str(' ', &data->formatted_str);
		*ft_strchr(data->found_flags, ' ') = 0;
	}
	str_result = ft_itoa(result);
	data->total_bytes_write += ft_strlen(str_result);
	return (str_result);
}

char	*ft_type_u(t_data *data)
{
	unsigned int	result;
	char			*str_result;

	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_str(result);
	data->total_bytes_write += ft_strlen(str_result);
	return (str_result);
}
