/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:57:49 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/18 09:54:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	free_data(t_data *data)
{
	free(data->original_src_str);
	free(data->formatted_str);
	va_end(data->va_ptr);
}

static void	interpret_format_string(t_data *data)
{
	while (*data->src_str)
	{
		if (*data->src_str != '%')
		{
			write(1, data->src_str, 1);
			data->src_str++;
			data->total_bytes_write++;
		}
		else
			ft_format(data);
	}
}

static int	intialize(const char *format_string, t_data *data)
{
	data->total_bytes_write = 0;
	data->src_str = ft_strdup(format_string);
	data->original_src_str = data->src_str;
	data->formatted_str = ft_strdup("");
	ft_strlcpy(data->valid_flags, "-0# +", 6);
	ft_strlcpy(data->valid_types, "diuxXcsp", 9);
	data->width = 0;
	data->precision = -1;
	return (0);
}

int	ft_printf(const char *format_string, ...)
{
	t_data	data;

	if (format_string[0] == 0)
		return (1);
	intialize(format_string, &data);
	va_start(data.va_ptr, format_string);
	interpret_format_string(&data);
	free_data(&data);
	return (data.total_bytes_write);
}
