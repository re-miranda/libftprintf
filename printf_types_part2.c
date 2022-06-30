/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:45:20 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/30 22:57:15 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_x(t_data *data)
{
	char			*swap;
	unsigned int	result;
	char			*str_result;
	char			*swap2;

	swap = data->formatted_str;
	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_base_str(result, "0123456789abcdef");
	if (ft_strchr(data->found_flags, '#'))
	{
		swap2 = str_result;
		str_result = ft_strjoin("0x", str_result);
		free(swap2);
	}
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}

void	ft_type_xx(t_data *data)
{
	char			*swap;
	unsigned int	result;
	char			*str_result;
	int				index;
	char			*swap2;

	index = 0;
	swap = data->formatted_str;
	result = va_arg(data->va_ptr, unsigned int);
	str_result = ft_uint_base_str(result, "0123456789abcdef");
	while (str_result[index])
	{
		str_result[index] = ft_toupper(str_result[index]);
		index++;
	}
	if (ft_strchr(data->found_flags, '#'))
	{
		swap2 = str_result;
		str_result = ft_strjoin("0X", str_result);
		free(swap2);
	}
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}

void	ft_type_p(t_data *data)
{
	char			*swap;
	size_t			result;
	char			*str_result;
	char			*swap2;

	swap = data->formatted_str;
	result = va_arg(data->va_ptr, size_t);
	if (result == 0)
		str_result = ft_strdup("(nil)");
	else
	{
		str_result = ft_sizet_base_str((size_t)result, "0123456789abcdef");
		swap2 = str_result;
		str_result = ft_strjoin("0x", str_result);
		free(swap2);
	}
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}
