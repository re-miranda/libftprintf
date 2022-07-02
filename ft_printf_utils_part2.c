/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_part2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:17 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/01 00:02:07 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_width(t_data *data, char *result)
{
	int		missing_width;
	char	*swap;
	char	*padding;
	char	padding_type;

	missing_width = data->width - ft_strlen(result);
	swap = result;
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
			result = ft_strjoin(result, padding);
		else
			result = ft_strjoin(padding, result);
		free(padding);
		free(swap);
	}
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
