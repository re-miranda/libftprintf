/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:58:40 by rmiranda          #+#    #+#             */
/*   Updated: 2022/07/20 21:53:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int				total_bytes_write;
	char			*src_str;
	char			*original_src_str;
	char			*formatted_str;
	va_list			va_ptr;
	char			valid_flags[6];
	char			valid_types[9];
	char			found_flags[6];
	unsigned int	width;
	int				precision;
	char			type;
}	t_data;

int		ft_printf(const char *format_string, ...);
char	*ft_result(t_data *data);
void	ft_type(t_data *data);
void	ft_precision(t_data *data);
void	ft_width(t_data *data);
void	ft_flags(t_data *data);
void	ft_format(t_data *data);
char	*ft_type_c(t_data *data);
char	*ft_type_s(t_data *data);
char	*ft_type_d_i(t_data *data);
char	*ft_type_u(t_data *data);
char	*ft_type_x(t_data *data);
char	*ft_type_xx(t_data *data);
char	*ft_type_p(t_data *data);
char	*ft_apply_width(t_data *data, char *result);
char	*ft_uint_base_str(unsigned int nbr, char *base);
char	*ft_uint_str(unsigned int n);
char	*ft_sizet_base_str(size_t nbr, char *base);
char	*ft_apply_precision(t_data *data, char *result);

#endif