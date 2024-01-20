/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	char	*cstr;
	int		i;
	int		sign;
	int		number;

	i = 0;
	number = 0;
	sign = 1;
	cstr = (char *)str;
	while ((cstr[i] >= 9 && cstr[i] <= 13) || cstr[i] == ' ')
		i++;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		if (cstr[i] == '-')
			sign *= -1;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		number = ((number * 10) + cstr[i] - '0');
		i++;
	}
	return (sign * number);
}

void	ft_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	main(int ac, char **arg)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(arg[1]);
		while (arg[2][i])
		{
			ft_bit(pid, arg[2][i]);
			i++;
		}
		ft_bit(pid, '\n');
	}
	else
	{
		ft_printf(">> insufficient argument <<\n");
		return (0);
	}
	return (0);
}
