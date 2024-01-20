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

#include "ft_printf.h"

void	ft_hx(unsigned int nb, char c, int *len)
{
	char	*str;
	char	*str1;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	if (c == 'x')
	{
		if (nb > 15)
		{
			ft_hx(nb / 16, c, len);
			ft_hx(nb % 16, c, len);
		}
		else
			ft_putchar(str[nb], len);
	}
	if (c == 'X')
	{
		if (nb > 15)
		{
			ft_hx(nb / 16, c, len);
			ft_hx(nb % 16, c, len);
		}
		else
			ft_putchar(str1[nb], len);
	}
}
