/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:27:32 by astrid            #+#    #+#             */
/*   Updated: 2022/07/10 21:25:14 by astrid           ###   ########.fr       */
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
		ft_printf("Please enter the server pid\n");
		return (1);
	}
	while (argv[2][i] != '\0')
	{
		sendCharInByte(pid, argv[2][i]);
		i++;
	}
	return (0);
}
