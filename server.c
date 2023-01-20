/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:48:02 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/20 13:08:38 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// The server program is called first. It doesn't take any arguments - an
// error will be displayed if there is an invalid number of arguments.

// If the program call is valid, we extract the server's process identifier
// (PID) with getpid(). A PID is a number to uniquely identify an active 
// process (here the server program), which is needed to be able to send 
// signals to the process and  manipulate it.

// Then, the signal() functions are called, which are used to specifiy which
// action should be performed if a particular signal is received by the
// program. In this case, if the program receives a SIGUSR1 or SIGUSR2 signal, 
// the bit_handler() function is executed.

// The purpose of the pause() function is to suspend the program execution
// until a signal arrives. Here, we put it into an infinite loop as we don't
// want the program to stop after the first signal is received but instead
// want it to continuously wait for more signals.

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
// position - as we start from left (pos 7) to right (pos 0) in client.c,
// we need to the same here by using (7 - shift) with shift = 0 being 
// the start value.

// If the signal is SIGUSR1, we are placing a 1 into the specified position of
// "byte". This is done using left bit shifting, which adds as many 0s to
// the end of the left operator as is specified by the right operator (e.g.,
// 1 << 3 = 1000).

// Once the client has sent all 8 bits of the binary representation of the 
// ASCII value and once they all have been handled, we can print the character 
// ("byte") and reset the bit_handler(), ready for the next character.

void	bit_handler(int signal)
{
	static int	byte;
	static int	shift;

	if (signal == SIGUSR1)
		byte += 1 << (7 - shift);
	shift++;
	if (shift == 8)
	{
		ft_printf("%c", byte);
		if (!(byte))
			ft_printf("\n");
		byte = 0;
		shift = 0;
	}
}
