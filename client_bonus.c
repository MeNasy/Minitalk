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

void	ft_bit_unix(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i <= 31)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		signal(SIGUSR1, ft_handler);
		usleep(100);
	}
}

void	ft_handler(int signal)
{
	static int	a = 0;

	if (a == 0 && signal == SIGUSR1)
	{
		ft_printf(">> signal received successfully <<\n");
		a++;
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
			ft_bit_unix(pid, arg[2][i]);
			i++;
		}
		ft_bit_unix(pid, '\n');
	}
	else
	{
		ft_printf(">> insufficient argument <<\n");
		return (0);
	}
	return (0);
}
