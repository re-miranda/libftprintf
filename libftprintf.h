/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:40 by rmiranda          #+#    #+#             */
/*   Updated: 2022/06/22 01:10:56 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef struct s_data
{
	int				total_bytes_write;
	char			*src_str;
	char			*formatted_str;
	va_list			va_ptr;
	char			valid_flags[6];
	char			valid_types[9];
	char			*found_flags;
	unsigned int	width;
	unsigned int	precision;
	char			type;
} t_data;

int		ft_printf(char *format_string, ...);
void		ft_flags(t_data data);
void	ft_append_char_to_str(t_data *data);
void	ft_format(t_data data);

#endif