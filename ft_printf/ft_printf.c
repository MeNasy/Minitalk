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

void	control(char c, va_list arg, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (c == '%')
		ft_putchar('%', len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (c == 'u')
		ft_unputnbr(va_arg(arg, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_hx(va_arg(arg, int), c, len);
	else if (c == 'p')
	{
		*len += write (1, "0x", 2);
		ft_voidhx(va_arg(arg, long unsigned), len);
	}
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			control (str[i], arg, &len);
		}
		else if (str[i] != '%')
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}
