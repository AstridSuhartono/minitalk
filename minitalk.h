#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

int		ft_atoi(const char *str);
void	sendCharInBits(int pid, unsigned char c);
int		main(int argc, char**argv);

#endif