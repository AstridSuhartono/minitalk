/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:27:32 by astrid            #+#    #+#             */
/*   Updated: 2022/07/07 00:45:08 by astrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, unsigned char c)
{
	int	bit;
	int	arr[8];

	bit = 0;
	while (bit < 8)
	{
		if (arr[bit] != NULL)
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
		ft_printf("wrong format entered\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}