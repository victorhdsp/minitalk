/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:30:45 by vide-sou          #+#    #+#             */
/*   Updated: 2025/01/09 09:18:32 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (int argc, char **argv)
{
    pid_t   server_pid;
    char    *message;
    int     index;

    index = 0;
    if (argc != 3)
        ft_error_message();
    server_pid = ft_atoi(argv[1]);
    message = argv[2];

    ft_putstr(message, 1);
    while(message[index])
    {
        get_bits_on_char(message[index], server_pid);
        index++;
    }
    get_bits_on_char(0, server_pid);
}