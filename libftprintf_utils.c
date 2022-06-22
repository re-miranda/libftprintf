/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:43 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/22 02:55:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_result(t_data *data)
{
	// ft_append_char_to_str('5', &data->formatted_str);
	if (data->type == 'c')
		ft_type_c(data);
	else if (data->type == 's')
		ft_type_s(data);
	else if (data->type == 'd' || data->type == 'i' )
		ft_type_d_i(data);
	else if (data->type == 'u' )
		ft_type_u(data);
}

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
	data->width = ft_atoi(data->src_str);
	while (ft_isdigit(*data->src_str))
		data->src_str++;
}

void	ft_flags(t_data *data)
{
	if (data->found_flags)
		free(data->found_flags);
	data->found_flags = ft_strdup("");
	while (ft_strchr(data->valid_flags, *data->src_str))
	{
		ft_append_char_to_str(*data->src_str, &data->found_flags);
		data->src_str++;
	}
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

void	ft_format(t_data *data)
{
	data->src_str++;
	if (*data->src_str == '%')
		return (ft_append_char_to_str('%', &data->formatted_str));
	ft_flags(data);
	ft_width(data);
	ft_precision(data);
	ft_type(data);
	ft_result(data);
}