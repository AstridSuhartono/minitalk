/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrid <astrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:36:05 by astrid            #+#    #+#             */
/*   Updated: 2022/07/10 00:37:33 by astrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handler(int signum)
{
    static int c;
    static int bit;

    if (signum == SIGUSR1)
        c += 1 << (7 - bit);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
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
    ft_printf("%d",getpid());
    while (argc == 1)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        pause();
    }
    return 0;
}