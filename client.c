/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:27:32 by astrid            #+#    #+#             */
/*   Updated: 2022/07/09 23:46:43 by astrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendCharInBit(int pid, unsigned char c)
{
	int	bit;
	int	binaryNum[8];

	bit = 7;
	while (c > 0)
	{
		binaryNum[bit--] = c % 2;
		c /= 2;
	}
	while (bit >= 0)
	{
		binaryNum[bit--] = 0;
	}
	bit = 0;
	while (bit < 8)
	{
		if (binaryNum[bit] != 0)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		bit++;
		usleep(300);
	}
}

int	main(int argc, char**argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("wrong argument numbers entered\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("Please enter a correct format\n");
		return (1);
	}
	while (argv[2][i] != '\0')
	{
		sendCharInBits(pid, argv[2][i]);
		i++;
	}
	return (0);
}
