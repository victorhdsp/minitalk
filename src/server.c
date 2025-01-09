/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:21 by vide-sou          #+#    #+#             */
/*   Updated: 2025/01/09 09:21:12 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void handler1(int signal)
{
    static  int count = CHAR_SIZE - 1;
    static  int value = 0;

    if (signal == SIGUSR2)
        value += 1 << count;
    count--;
    if (count < 0)
    {
        if (value == 0)
            ft_putstr("\n", 1);
        else
            ft_putchar(value, 1);
        count = CHAR_SIZE - 1;
        value = 0;
    }
}

int main()
{
    pid_t pid = getpid();
    
    ft_putnbr(pid, 1);
    ft_putstr("\n", 1);
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler1);      
    while (1)
        usleep(10);
}