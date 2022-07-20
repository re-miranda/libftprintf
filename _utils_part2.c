/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:17 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/20 21:53:12 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_precision(t_data *data, char *result)
{
	char	*swap;
	char	sign[2];

	swap = result;
	sign[0] = swap[0];
	sign[1] = 0;
	if (data->precision == -1)
		return (result);
	if (data->type == 's')
		result[data->precision] = 0;
	if (data->type == 'd' || data->type == 'i' || data->type == 'u'
		|| data->type == 'x' || data->type == 'X')
	{
		if ((size_t)data->precision >= ft_strlen(result))
		{
			result = ft_calloc(sizeof(char), data->precision + 1);
			ft_memset(result, '0', data->precision);
			if (*swap == '-' || *swap == '+' || *swap == ' ')
			{
				ft_memcpy((result + data->precision - ft_strlen(swap) + 1),
					(swap + 1), data->precision);
				free(swap);
				swap = result;
				result = ft_strjoin(sign, result);
			}
			else
				ft_memcpy((result + data->precision - ft_strlen(swap)),
					swap, data->precision);
			free(swap);
		}
		else if (data->precision == 0 && result[0] == '0')
			result[0] = 0;
	}
	return (result);
}

char	*ft_apply_width(t_data *data, char *result)
{
	int		missing_width;
	char	sign[2];
	char	*swap;
	char	*padding;
	char	padding_type;

	swap = result;
	sign[0] = *result;
	sign[1] = 0;
	missing_width = data->width - ft_strlen(result);
	padding_type = ' ';
	if (ft_strchr(data->found_flags, '0'))
	{
		if (data->precision == -1 && !ft_strchr(data->found_flags, '-'))
			padding_type = '0';
	}
	if (missing_width > 0)
	{
		if (padding_type == '0' && (data->type == 'd' || data->type == 'i') && !ft_isdigit(*sign))
			result++;
		data->total_bytes_write += missing_width;
		padding = ft_calloc(1, missing_width + 1);
		ft_memset(padding, padding_type, missing_width);
		if (ft_strchr(data->found_flags, '-'))
			result = ft_strjoin(result, padding);
		else
			result = ft_strjoin(padding, result);
		free(padding);
		free(swap);
		if (padding_type == '0' && !ft_isdigit(*sign) && (data->type == 'd' || data->type == 'i'))
		{
			swap = result;
			result = ft_strjoin(sign, result);
			free(swap);
		}
	}
	data->width = 0;
	return (result);
}

char	*ft_result(t_data *data)
{
	if (data->type == 'c')
		return (ft_type_c(data));
	else if (data->type == 's')
		return (ft_type_s(data));
	else if (data->type == 'd' || data->type == 'i' )
		return (ft_type_d_i(data));
	else if (data->type == 'u' )
		return (ft_type_u(data));
	else if (data->type == 'x' )
		return (ft_type_x(data));
	else if (data->type == 'X' )
		return (ft_type_xx(data));
	else if (data->type == 'p' )
		return (ft_type_p(data));
	return (NULL);
}
