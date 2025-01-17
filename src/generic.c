/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:13 by vide-sou          #+#    #+#             */
/*   Updated: 2025/01/17 15:22:10 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits_on_char(int c, pid_t pid)
{
	int	i;

	i = CHAR_SIZE;
	while (i--)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(U_SECOND);
	}
}

int	send_message(char *message, pid_t pid)
{
	int	index;

	index = 0;
	while (message[index])
	{
		get_bits_on_char(message[index], pid);
		index++;
	}
	get_bits_on_char(0, pid);
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *nptr)
{
	char	*nb;
	long	result;
	int		minus;

	nb = (char *)nptr;
	result = 0;
	minus = 0;
	while (*nb == 32 || (*nb >= 9 && *nb <= 13))
		nb++;
	if ((*nb == '+') || (*nb == '-'))
	{
		if (*nb == '-')
			minus = 1;
		nb++;
	}
	while (ft_isdigit(*nb))
		result = (result * 10) + (*nb++ - 48);
	if (minus)
		result *= -1;
	return ((int)result);
}
