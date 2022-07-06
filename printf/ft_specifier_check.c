/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuharto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:31:43 by asuharto          #+#    #+#             */
/*   Updated: 2022/06/25 18:31:44 by asuharto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier_check(const char c, va_list arg, int *i)
{
	if (c == 'c')
		return (ft_char_print(va_arg(arg, int)));
	if (c == 's')
		return (ft_str_print(va_arg(arg, char *)));
	if (c == 'i' || c == 'd')
		return (ft_nbr_print(va_arg(arg, int)));
	if (c == 'u')
		return (ft_nbr_print(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex_print(va_arg(arg, unsigned int), c));
	if (c == 'p')
		return (ft_hex_print(va_arg(arg, unsigned long), c));
	if (c == '%')
		return (ft_char_print(c));
	if (!c)
		return (0);
	else
		*i = *i - 1;
	return (0);
}
