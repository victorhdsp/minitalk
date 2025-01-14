/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:21 by vide-sou          #+#    #+#             */
/*   Updated: 2025/01/14 19:14:24 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bit_handler(int signal, siginfo_t *info, void *notused)
{
    static  int count = CHAR_SIZE - 1;
    static  int value = 0;
    (void)notused;

    if (signal == SIGUSR2)
        value += 1 << count;
    count--;
    if (count < 0)
    {
        if (value == 0)
        {
            send_message("Done", info->si_pid);
            ft_putstr("\n", 1);
        }
        else
            ft_putchar(value, 1);
        count = CHAR_SIZE - 1;
        value = 0;
        usleep(SIS_TIME);
    }
}

int main()
{
    pid_t pid = getpid();
    struct sigaction action;

    action.sa_sigaction = bit_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    ft_putnbr(pid, 1);
    ft_putstr("\n", 1);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);  
    while (1)
        usleep(SIS_TIME);
}