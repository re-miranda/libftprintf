/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:57:49 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/22 00:51:37 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	free_data(t_data *data)
{
	free(data->src_str);
	free(data->formatted_str);
	free(data->found_flags);
}

static void	formatted_string_to_stdout(t_data *data)
{
	write(1, data->formatted_str, data->total_bytes_write);
}

static void	interpret_format_string(t_data *data)
{
	while (*data->src_str)
	{
		if (*data->src_str != '%')
		{
			ft_append_char_to_str(*data->src_str, &data->formatted_str);
			data->src_str++;
		}
		else
			ft_format(data);
	}
	data->total_bytes_write = strlen(data->formatted_str);
}

static int	protect_and_intialize(const char *format_string, t_data *data)
{
	if (format_string[0] == 0)
		return (-1);
	data->total_bytes_write = 0;
	data->src_str = ft_strdup(format_string);
	data->formatted_str = ft_strdup("");
	ft_strlcpy("-0# +", data->valid_flags, 6);
	ft_strlcpy("diuxXcsp", data->valid_types, 9);
	return (0);
}

int	ft_printf(const char *format_string, ...)
{
	t_data	data;

	if (protect_and_intialize(format_string, &data))
		return (0);
	va_start(data.va_ptr, format_string);
	interpret_format_string(&data);
	formatted_string_to_stdout(&data);
	free_data(&data);
	return (data.total_bytes_write);
}
