/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:48:02 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/19 15:15:38 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// The server program is called first. It doesn't take any arguments - an
// error will be displayed if there is an invalid number of arguments.

// If the program call is valid, we extract the server's process identifier
// (PID) with getpid(). A PID is a number to uniquely identify an active 
// process (here the server program), which is needed to be able to send 
// signals to the process and  manipulate it.

// Signal()
// Purpose of pause()

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		ft_printf("Error! Did you mean: ./server?\n");
	else
	{
		pid = getpid();
		ft_printf("Process Identifier (PID): %d\n", pid);
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		while (1)
			pause();
	}
	return (0);
}

// The bit_handler() takes a signal as an argument - in this case, it is 
// either SIGUSR1 or SIGUSR2.

// Similarly to client.c, the "shift" variable demonstrates the bit 
// position - as we start from right (pos 0) to left (pos 7) in client.c, here,
// we need to the same.

// If the signal is SIGUSR1, we are placing a 1 into the specified position of
// "byte".

// Once the client has sent all 8 bits of the binary representation of the ASCII 
// value and once they all have been handled, we can print the character ("byte")
// and reset the bit_handler(), ready for the next character.

void	bit_handler(int signal)
{
	static int	byte;
	static int	shift;
	
	if (signal == SIGUSR1)
		byte += 1 >> shift;
	shift++;
	// 7?
	if (shift == 8)
	{
		ft_printf("%c", byte);
		if (!byte)
			ft_printf("\n");
		byte = 0;
		shift = 0;
	}
}
