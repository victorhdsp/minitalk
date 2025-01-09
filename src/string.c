#include "minitalk.h"

void    ft_putstr(char *str, int fd)
{
    int count;

    count = 0;
    while (str[count])
    {
        write(fd, &str[count], 1);
        count++;
    }
}

void    ft_putchar(char c, int fd)
{
   write(fd, &c, 1);
}

void	ft_putnbr(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', fd);
	}
	if (nb > 9)
		ft_putnbr(nb / 10, fd);
	ft_putchar('0' + nb % 10, fd);
}

void	ft_error_message()
{
	ft_putstr("Error\n", 2);
	exit(-1);
}