/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:20:48 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/19 15:45:30 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Once we know the PID of the server, the client program can be called. It
// takes two arguments - the server's PID and the message that we want to send
// to the server. An error will be displayed if there is an invalid number of
// arguments.

// If the program call is valid, we first transform the PID into an integer as
// this format is needed for the later called kill() function.

// Then, we initialize the process of sending the message to the server by
// using the function send_bit().

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("Error! Did you mean: ./client [pid] ['message']?\n");
	else
	{
		pid = ft_atoi(argv[1]);
		send_bit(pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}

// The send_bit() function takes three arguments - the server's PID, the
// message, and the length of the message.

// We loop through the message to access each of its characters to then
// encode it and send signals to the server.

// Digital signals are binary signals, i.e., they are composed of only 0s and 
// 1s.The ASCII characters that we are trying to send to the server can be 
// written in binary and require 8 bits each. Therefore, we are looping through 
// the binary representation of each character 8 times. The "shift" variable
// demonstrates the bit position, here going from left (pos 7) to right (pos 0).

// The single ampersand is a bitwise AND operator. In our case, it basically
// compares the bit at the specified position and 1. If they are the same, i.e.,
// if the bit at the specified position is 1, we send the SIGUSR1 signal to the 
// server. Otherwise, if the bit at the specified position is 0, we send the
// SIGUSR2 to the server. This is done by using the kill() function.

// The usleep(x) function suspends execution of the program for x
// microseconds. The purpose is to allow sufficient time for the signal to be
// sent to and processed by the server.

void	send_bit(int pid, char *message, int len)
{
	int	i;
	int	shift;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((message[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			shift--;
		}
		i++;
	}
}
