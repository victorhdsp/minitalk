/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vide-sou <vide-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:32:03 by vide-sou          #+#    #+#             */
/*   Updated: 2025/01/09 08:43:41 by vide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define CHAR_SIZE 8

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void ft_putstr(char *str, int fd);
void ft_putchar(char c, int fd);
void ft_putnbr(int n, int fd);
void ft_error_message();
int ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void get_bits_on_char (int c, pid_t pid);

#endif