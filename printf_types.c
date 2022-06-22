/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:37:07 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/22 02:55:35 by rmiranda         ###   ########.fr       */
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
	
	swap = data->formatted_str;
	result = va_arg(data->va_ptr, int);
	str_result = ft_itoa(result);
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}

void	ft_type_d_i(t_data *data)
{
	char	*swap;
	int		result;
	char	*str_result;
	
	swap = data->formatted_str;
	result = va_arg(data->va_ptr, int);
	str_result = ft_itoa(result);
	data->formatted_str = ft_strjoin(swap, str_result);
	free(swap);
	free(str_result);
}
