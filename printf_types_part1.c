/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:37:07 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/23 01:46:04 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_c(t_data *data)
{
	ft_append_char_to_str(va_arg(data->va_ptr, int), &data->formatted_str);
}

void	ft_type_s(t_data *data)
{
	char	*swap;
	char	*result;

	swap = data->formatted_str;
	result = va_arg(data->va_ptr, char *);
	data->formatted_str = ft_strjoin(swap, result);
	free(swap);
}

void	ft_type_d_i(t_data *data)
{
	char	*swap;
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
	swap = data->formatted_str;
	str_result = ft_itoa(result);
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}
