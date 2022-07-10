/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:36:05 by astrid            #+#    #+#             */
/*   Updated: 2022/07/10 19:31:24 by astrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handler(int signum)
{
    static int c;
    static int bitCount;

    if (signum == SIGUSR1)
        c += 1 << (7 - bitCount);
    bitCount++;
    if (bitCount == 8)
    {
        write(1, &c, 1);
        bitCount = 0;
        c = 0;
    }
}

int main(int argc,char** argv)
{
    struct  sigaction action;

    (void)argv;
    action.sa_handler = &handler;
    if (argc != 1)
    {
        ft_printf("Error, wrong format");
        return (1);
    }
    ft_printf("Server pid: %d",getpid());
    write(1,'\n',1);
    while (argc == 1)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        pause();
    }
    return 0;
}