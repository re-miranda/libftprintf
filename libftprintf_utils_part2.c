/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils_part2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:17 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/30 23:01:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_apply_width(t_data *data)
{
	int		missing_width;
	char	*swap;
	char	*padding;
	char	padding_type;

	missing_width = data->width - data->total_bytes_write;
	swap = data->formatted_str;
	padding_type = ' ';
	if (ft_strchr(data->found_flags, '0'))
	{
		if (!data->precision && !ft_strchr(data->found_flags, '-'))
			padding_type = '0';
	}
	if (missing_width > 0)
	{
		data->total_bytes_write += missing_width;
		padding = ft_calloc(sizeof(char), missing_width + 1);
		ft_memset(padding, padding_type, missing_width);
		if (ft_strchr(data->found_flags, '-'))
			data->formatted_str = ft_strjoin(data->formatted_str, padding);
		else
			data->formatted_str = ft_strjoin(padding, data->formatted_str);
		free(padding);
		free(swap);
	}
}

void	ft_result(t_data *data)
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
}

void	ft_append_char_to_str(char c, char **str)
{
	char	*swap;
	char	char_str[2];

	swap = *str;
	char_str[0] = c;
	char_str[1] = 0;
	*str = ft_strjoin(swap, char_str);
	free(swap);
}
