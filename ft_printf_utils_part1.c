/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_part1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:43 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/02 22:38:37 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(t_data *data)
{
	data->type = 0;
	if (ft_strchr(data->valid_types, *data->src_str))
	{
		data->type = *data->src_str;
		data->src_str++;
	}
}

void	ft_precision(t_data *data)
{
	if (*data->src_str == '.')
		data->src_str++;
	data->precision = ft_atoi(data->src_str);
	while (ft_isdigit(*data->src_str))
		data->src_str++;
}

void	ft_width(t_data *data)
{
	data->width = 0;
	if (ft_isdigit(*data->src_str))
		data->width = ft_atoi(data->src_str);
	while (ft_isdigit(*data->src_str))
		data->src_str++;
}

void	ft_flags(t_data *data)
{
	while (ft_strchr(data->valid_flags, *data->src_str))
	{
		ft_memset(ft_strchr(data->found_flags, 0), *data->src_str, 1);
		data->src_str++;
	}
}

void	ft_format(t_data *data)
{
	char	*result;

	data->src_str++;
	if (*data->src_str == '%')
	{
		data->total_bytes_write ++;
		data->src_str++;
		write(1, "%", 1);
		return ;
	}
	ft_flags(data);
	ft_width(data);
	ft_precision(data);
	ft_type(data);
	result = ft_result(data);
	result = ft_apply_width(data, result);
	write(1, result, ft_strlen(result));
	free(result);
}
