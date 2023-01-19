/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:48:02 by lvogelsa          #+#    #+#             */
/*   Updated: 2023/01/19 11:05:06 by lvogelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	bit_handler(int signal)
{
	static int	byte;
	static int	location;
	
	if (signal == SIGUSR1)
		byte += 1 << (7 - location);
	location++;
	if (location == 8)
	{
		ft_printf("%c", byte);
		if (!byte)
			ft_printf("\n");
		byte = 0;
		location = 0;
	}
}
