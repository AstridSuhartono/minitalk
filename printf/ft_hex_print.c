/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuharto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:28:25 by asuharto          #+#    #+#             */
/*   Updated: 2022/06/25 18:59:52 by asuharto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_print(unsigned long n, char c)
{
	int	count;

	count = ft_nbr_count(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ft_hex_print(n / 16, c);
		ft_hex_print(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n - 10 + 'a', 1);
		else
			ft_putchar_fd(n - 10 + 'A', 1);
	}
	return (count);
}
