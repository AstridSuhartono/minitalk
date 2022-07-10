/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_Bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:09:00 by astrid            #+#    #+#             */
/*   Updated: 2022/07/10 21:34:36 by astrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendCharInByte(int pid, unsigned char c)
{
	int	bitCount;
	int	binaryNum[8];

	bitCount = 7;
	while (c > 0)
	{
		binaryNum[bitCount--] = c % 2;
		c /= 2;
	}
	while (bitCount >= 0)
		binaryNum[bitCount--] = 0;
	bitCount = 0;
	while (bitCount < 8)
	{
		if (binaryNum[bitCount] != 0)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		bitCount++;
		usleep(300);
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Signal from client received");
		write(1, '\n', 1);
	}	
}

int	main(int argc, char **argv)
{
	struct  sigaction action;
	int	pid;
	int	i;

    action.sa_handler = &handler;
	i = 0;
	if (argc != 3)
	{
		ft_printf("wrong argument numbers entered\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		sendCharInByte(pid, argv[2][i]);
		i++;
	}
	return (0);
}